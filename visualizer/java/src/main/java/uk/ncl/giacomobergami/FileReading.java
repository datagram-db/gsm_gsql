package uk.ncl.giacomobergami;

import it.giacomobergami.datatypelang.gui.MultiTaskEditor;
import org.apache.xpath.operations.Mult;

import javax.swing.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Date;
import java.util.Iterator;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

public class FileReading {
//    public static void main(String args[]) throws IOException {
//        if (args.length >= 2) {
//            String command = args[0];
//            String file = args[1];
//            if (command.equals("file")) {
//                writeFile(file);
//            } else {
//                Files.list(Path.of(file)).forEach(x -> {
//                    try {
//                        FileReading.writeFile(x);
//                    } catch (IOException e) {
//                        throw new RuntimeException(e);
//                    }
//                });
//            }
//        }
//
//    }

    public static void writeFile(String file, MultiTaskEditor panel) throws IOException {
        writeFile(Paths.get(file), panel);
    }

    private static void writeFile(Path p, MultiTaskEditor panel) throws IOException {
        StanfordGraph.reset();
        PropertyGraph.reset();
//        AtomicInteger ai = new AtomicInteger(0);

        {
            BufferedWriter bw = new BufferedWriter(new FileWriter(p.toString() +".gsm.txt"));
            Date startDate = new Date();
            Date endDate = new Date(Long.MAX_VALUE);
            var ls = Files.readAllLines(p);
            panel.init(ls.size());
//            ProgressBarExample m=new ProgressBarExample(ls.size());
//            m.setVisible(true);
            for (int i = 0; i<ls.size(); i++) {
                panel.count();
//                    st.setProgress((i*100)/ls.size());
//                if ((i % 100 )==0)
//                    System.out.println(i+"/"+ls.size());
                StringBuilder sb = new StringBuilder();
                StanfordGraph
                        .parse(ls.get(i), startDate, endDate)
                        .asYAMLObjectCollection(sb);
                bw.write(sb.toString());
                if (i != (ls.size()-1)) {
                    bw.write("~~\n");
                }
            }
            panel.done();
//            m.setVisible(false);
//            m.dispose();
//            st.setProgress(100);
            bw.flush();
            bw.close();
        }
    }
}
