package it.giacomobergami.datatypelang.gui; /**
 * Created by vasistas on 18/12/16.
 */
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.myToken;
import it.giacomobergami.datatypelang.gui.editor.GUIUtils;
import it.giacomobergami.datatypelang.gui.editor.KeywordStyledDocument;
import it.giacomobergami.datatypelang.gui.styles.StyleCollection;
import it.giacomobergami.datatypelang.utils.ForFiles;
import uk.ncl.giacomobergami.FileReading;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.Arrays;
import java.util.Properties;
import java.util.function.Consumer;
import java.util.stream.Stream;

import static java.nio.file.StandardCopyOption.REPLACE_EXISTING;
import static javax.swing.JFileChooser.CANCEL_OPTION;
import static javax.swing.JFileChooser.ERROR_OPTION;

public class MultiTaskEditor extends JFrame  {
    private static final long serialVersionUID = 1L;
    KeywordStyledDocument ksd;
    JProgressBar jb;
    JLabel label;

    public static JMenuItem item(String label, Consumer<ActionEvent> action, KeyStroke stroke) {
        JMenuItem menuItem = new JMenuItem(new AbstractAction(label) {
            public void actionPerformed(ActionEvent e) {
                action.accept(e);
            }
        });
        if (stroke!=null) menuItem.setAccelerator(stroke);
        return menuItem;
    }

    boolean deleteDirectory(File directoryToBeDeleted) {
        if (directoryToBeDeleted.exists() && directoryToBeDeleted.isDirectory()) {
            File[] allContents = directoryToBeDeleted.listFiles();
            if (allContents != null) {
                for (File file : allContents) {
                    deleteDirectory(file);
                }
            }
            return directoryToBeDeleted.delete();
        }
        return false;
    }

    public  void copyFolder(Path src, Path dest) throws IOException {
        try (Stream<Path> stream = Files.walk(src)) {
            stream.forEach(source -> copy(source, dest.resolve(src.relativize(source))));
        }
    }

    private void copy(Path source, Path dest) {
        try {
            Files.copy(source, dest, REPLACE_EXISTING);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage(), e);
        }
    }

    public  JMenuBar bar() {
        JMenuBar menuBar;
        JMenu file, compile;
        JMenuItem menuItem;


//Create the file bar.
        menuBar = new JMenuBar();



//Build the first file.
        file = new JMenu("File");
        file.setMnemonic(KeyEvent.VK_A);
        file.getAccessibleContext().setAccessibleDescription(
                "File oerations");
        file.add(item("Transform sentences to Object-Oriented DB…", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Choose the sentence file…");
            int n = fc.showOpenDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                try {
                    FileReading.writeFile(f.getAbsolutePath(), this);
                } catch (IOException e) {

                    JOptionPane optionPane = new JOptionPane(e.toString(), JOptionPane.ERROR_MESSAGE);
                    JDialog dialog = optionPane.createDialog("ERROR");
                    dialog.setAlwaysOnTop(true);
                    dialog.setVisible(true);
                }
            }
        }, null));
        file.add(item("Load DatagramQL query…", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Choose the input file…");
            int n = fc.showOpenDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                ksd.clear();
                setText(ForFiles.toString(f));
            }
        },null));

        file.add(item("Save DatagramQL query…", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Save query file…");
            int n = fc.showSaveDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                try {
                    ksd.writeFile(f);
                } catch (IOException | BadLocationException e) {
                    JOptionPane optionPane = new JOptionPane(e.toString(), JOptionPane.ERROR_MESSAGE);
                    JDialog dialog = optionPane.createDialog("ERROR");
                    dialog.setAlwaysOnTop(true);
                    dialog.setVisible(true);
                }
            }
        },null));
        file.add(item("Run current query", x->{
            File query_file = null;
            try {
                query_file = File.createTempFile("query", ".txt");
                ksd.writeFile(query_file);
            } catch (IOException | BadLocationException e) {
                JOptionPane optionPane = new JOptionPane(e.toString(), JOptionPane.ERROR_MESSAGE);
                JDialog dialog = optionPane.createDialog("ERROR");
                dialog.setAlwaysOnTop(true);
                dialog.setVisible(true);
            }
            if (query_file != null) {
                Properties prop = new Properties();
                try (FileInputStream fis = new FileInputStream("configuration.properties")) {
                    prop.load(fis);
                    String cpp = prop.getProperty("cpp", "./");
                    String dst = prop.getProperty("dst_file", "");
                    var current = Path.of("viz", "data").toAbsolutePath();
                    deleteDirectory(current.toFile());
                    current.toFile().mkdirs();
                    JFileChooser fc = new JFileChooser();
                    fc.setToolTipText("Choose the sentence file…");
                    int n = fc.showOpenDialog(MultiTaskEditor.this);
                    File existingFiles = null;
                    File data =null;
                    if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                        data = fc.getSelectedFile();
                        existingFiles = new File(data.getAbsolutePath()+".gsm.txt");
                        if (!existingFiles.exists()) {
                            try {
                                FileReading.writeFile(data.getAbsolutePath(), this);
                            } catch (IOException e) {
                                JOptionPane optionPane = new JOptionPane(e.toString(), JOptionPane.ERROR_MESSAGE);
                                JDialog dialog = optionPane.createDialog("ERROR");
                                dialog.setAlwaysOnTop(true);
                                dialog.setVisible(true);
                            }
                        }
                    }
                    String[] commands = new String[]{Path.of(cpp, "cmake-build-release", "gsm2_server").toString(),
                            query_file.getAbsolutePath(),
                            existingFiles.getAbsolutePath(),
                            "-iortv",
                            "-z",
                            "pos\nSizeTAtt\nbegin\nSizeTAtt\nend\nSizeTAtt",
                            "-b",
                            "benchmarks.csv"};

                    Process process = new ProcessBuilder(commands).start();
                    InputStream is = process.getInputStream();
                    InputStreamReader isr = new InputStreamReader(is);
                    BufferedReader br = new BufferedReader(isr);
                    String line;
                    System.out.println("Output of running  is:");
                    while ((line = br.readLine()) != null) {
                        System.out.println(line);
                    }
                    Files.copy(data.toPath(), Path.of("viz", "data", "sentences.txt"), REPLACE_EXISTING);
                    var target = Path.of(dst).toAbsolutePath();
                    if (!current.equals(target)) {
                        deleteDirectory(target.toFile());
                        copyFolder(current, target);
                    }
                    if (Desktop.isDesktopSupported() && Desktop.getDesktop().isSupported(Desktop.Action.BROWSE)) {
                        try {
                            Desktop.getDesktop().browse(new URI("http://127.0.0.1:9999"));
                        } catch (IOException | URISyntaxException e) {
                            throw new RuntimeException(e);
                        }
                    } else {
                        JOptionPane optionPane = new JOptionPane("OS does not support using default browser: please open http://127.0.0.1:9999", JOptionPane.INFORMATION_MESSAGE);
                        JDialog dialog = optionPane.createDialog("ERROR");
                        dialog.setAlwaysOnTop(true);
                        dialog.setVisible(true);
                    }
                } catch (IOException ex) {
                    JOptionPane optionPane = new JOptionPane(ex.toString(), JOptionPane.ERROR_MESSAGE);
                    JDialog dialog = optionPane.createDialog("ERROR");
                    dialog.setAlwaysOnTop(true);
                    dialog.setVisible(true);
                }

            }
        }, null));
        file.add(item("Open cached results in browser…", x->{
            if (Desktop.isDesktopSupported() && Desktop.getDesktop().isSupported(Desktop.Action.BROWSE)) {
                try {
                    Desktop.getDesktop().browse(new URI("http://127.0.0.1:9999"));
                } catch (IOException | URISyntaxException e) {
                    throw new RuntimeException(e);
                }
            } else {
                JOptionPane optionPane = new JOptionPane("OS does not support using default browser: please open http://127.0.0.1:9999", JOptionPane.INFORMATION_MESSAGE);
                JDialog dialog = optionPane.createDialog("ERROR");
                dialog.setAlwaysOnTop(true);
                dialog.setVisible(true);
            }
        }, null));
        menuBar.add(file);



        compile = new JMenu("Compile");
        compile.setMnemonic(KeyEvent.VK_F5);
        file.getAccessibleContext().setAccessibleDescription(
                "Compile operations");
//        file.add(item("Load grammar…", x-> {
//            JFileChooser fc = new JFileChooser();
//            fc.setToolTipText("Choose the input file…");
//            int n = fc.showOpenDialog(MultiTaskEditor.this);
//            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
//                File f = fc.getSelectedFile();
//                ksd.clear();
//                setText(ForFiles.toString(f));
//            }
//        },null));
//        file.add(item("Check", x-> {
//            JFileChooser fc = new JFileChooser();
//            fc.setToolTipText("Choose the input file…");
//            int n = fc.showOpenDialog(MultiTaskEditor.this);
//            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
//                File f = fc.getSelectedFile();
//                ksd.clear();
//                setText(ForFiles.toString(f));
//            }
//        },null));
        menuBar.add(file);

//a group of JMenuItems
        return menuBar;
        /*JMenuBar mb = new JMenuBar();
        JMenu file = new JMenu("File");
        file.setMnemonic(KeyEvent.VK_A);
        file.getAccessibleContext().setAccessibleDescription(
                "The only file in this program that has file items");
        JMenu bar = createMenu("File", KeyEvent.VK_0);
        mb.add(bar);
        JMenuItem itm = createMenuItem("Load Source…", new MenuAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("PPPP");
            }
        });
        bar.add(itm);
        return mb;*/
    }

    public  JMenu createMenu(String name, int keyEvent, Component... items) {
        JMenu menu = new JMenu(name);
        menu.setMnemonic(keyEvent);
        for (Component item : items) {
            menu.add(item);
        }
        return menu;
    }

    public JMenuItem createMenuItem(String name, MenuAction a) {
        JMenuItem jmi = new JMenuItem(name);
        jmi.setAction(a);
        return jmi;
    }
    int i = 0;

    public MultiTaskEditor(StyleCollection sc) {
        ksd = new KeywordStyledDocument(sc, this);
        final JTextPane pane = new JTextPane(ksd);
        pane.setFont(GUIUtils.monospace());
        JScrollPane scrollPane = new JScrollPane(pane);
        label = new JLabel("Welcome do DataType Language.");
        jb=new JProgressBar(0,100);
        jb.setValue(0);
        jb.setStringPainted(true);
        i = 0;

        getContentPane().add(scrollPane, BorderLayout.CENTER);
        getContentPane().add(bar(),BorderLayout.NORTH);

        GridLayout experimentLayout = new GridLayout(0,2);
        JPanel controls = new JPanel();
        controls.setLayout(experimentLayout);
        controls.add(label);
        controls.add(jb);

        getContentPane().add(controls, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(375, 400);
        //pack();
        setLocationByPlatform(true);
    }

    public void init(int max) {
        label.setText("Transforming full-text sentences into graphs...");
        label.repaint();
        label.update(label.getGraphics());
        jb.setValue(0);
        jb.setMaximum(max);
        i = 0;
        jb.setValue(0);
        jb.repaint();
        jb.update(jb.getGraphics());
    }

    public void done() {
        label.setText("Transformation was done.");
        label.repaint();
        jb.setValue(0);
        i = 0;
        label.update(label.getGraphics());
    }

    public void count() {
        System.out.println(i);
        jb.setValue(++i);
        jb.repaint();
        jb.update(jb.getGraphics());
    }

    public void setLabel(String msg){
        label.setText(msg);
    }

    public void setError(myToken t) {
        ksd.setError(t);
    }

    public void clear() {

    }

    public void setText(String text) {
        try {
            ksd.insertString(0,text,null);
        } catch (BadLocationException e) {
            throw new RuntimeException(e);
        }
    }

}