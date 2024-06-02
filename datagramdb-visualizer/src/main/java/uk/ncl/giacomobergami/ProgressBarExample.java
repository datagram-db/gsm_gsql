package uk.ncl.giacomobergami;

import javax.swing.*;
    public class ProgressBarExample extends JFrame{    
    JProgressBar jb;    
    int i=0,num=0;     
    public ProgressBarExample(int max){
    jb=new JProgressBar(0,max);
    jb.setBounds(40,40,160,30);         
    jb.setValue(0);    
    jb.setStringPainted(true);    
    add(jb);    
    setSize(250,150);    
    setLayout(null);
//    pack();
    }    
    public void iterate(){
      jb.setValue(++i);
    }    
    public static void main(String[] args) throws InterruptedException {
        ProgressBarExample m=new ProgressBarExample(2000);
        m.setVisible(true);
        int i = 0;
        while(i<=2000){
            m.iterate();
            Thread.sleep(1);
            i++;
        }
    }    
    }    