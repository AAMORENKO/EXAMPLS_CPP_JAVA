package GUIproLib;

import java.io.File;
import java.nio.CharBuffer;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.List;

public class GUIproLib extends  Frame implements
        WindowListener {

    public int x, y, w, h;
    public int x1, y1, x2, y2, x3, y3;
    public int cr, cq, cb;
    public int d;
    public int cx, cy, dx, dy;

    public String ms="";

    public void windowOpened(WindowEvent e) {    }    ;

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) { };
    public void windowIconified(WindowEvent e) { };
    public void windowDeiconified(WindowEvent e) { };
    public void windowActivated(WindowEvent e) { };
    public void windowDeactivated(WindowEvent e) { };

    public int count=0;

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        float wdk = 3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        // TO DO init

        ms = "Перший файл. Pадіуси кіл:";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 16));
        g.setColor(new Color(0, 0, 0));
        g.drawString(ms, 100, 105);

        List<Double> list = new ArrayList<Double>(); //текстовий масив
        double[] radius = new double[12]; //таблиця для радіусів
        File file = new File("radius.txt");
        BufferedReader reader = null;
        int p=0;
        try {
            reader = new BufferedReader(new FileReader(file));
            String text = null;

            while ((text = reader.readLine()) != null) {
                list.add(Double.parseDouble(text));
                radius[p]=Double.parseDouble(text);//заповнення даними з файлу
                p++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();//закрити файл
                }
            } catch (IOException e) {
            }
        }

        double[] dlina=new double[12];
        double[] ploscha=new double[12];

        final double pi=3.1415926535897932384626433832795;

        // TO DO DRAW

        for (int i = 0; i <p; i++) {
            g.drawString(String.valueOf(list.get(i)),100,140+i*20);
            dlina[i]=2*pi*radius[i];
            ploscha[i]=pi*radius[i]*radius[i];
        }

        ms="Другий файл:";
        g.drawString(ms,100,140+(p+1)*20);

        ms="radius     dlina      ploschad";
        g.drawString(ms,100+60,140+(p+3)*20);
        int k=0;
        String txt="";
        for (int i = 0; i <p; i++) {
            if(dlina[i]>7 && dlina[i]<10)
            {
                g.drawString(String.valueOf(radius[i]),100+60,480+k*20);
                g.drawString(String.valueOf(dlina[i]),100+130,480+k*20);
                g.setColor(new Color(255, 255, 255));
                g.fillRect(100+130+42,480+k*20-16,400,40);
                g.setColor(new Color(0, 0, 0));
                g.drawString(String.valueOf(ploscha[i]),100+200,480+k*20);
                g.setColor(new Color(255, 255, 255));
                g.fillRect(100+200+42,480+k*20-16,400,40);
                g.setColor(new Color(0, 0, 0));

                        txt += String.valueOf(radius[i]);
                        txt += "\t\t";
                        txt += String.valueOf(dlina[i]);
                        txt += "\t\t";
                        txt += String.valueOf(ploscha[i]);
                        txt += "\n";

                k++;
            }
        }

        //Запис до іншого файлу ....
        // Можна так, але є проблема...
        File wfile = new File("result.txt");
        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter(wfile));
            writer.write(txt);
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try {
                writer.flush();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

/*
        ms="Результати перевірки:";
        g.drawString(ms,420,105);


        String[] spisok = new String[15];
        int[] marks = new int[15];
        file = new File("class.txt");
        reader = null;
        p=0;
        try {
            reader = new BufferedReader(new FileReader(file));
            String text = null;

            while ((text = reader.readLine()) != null) {
                spisok[p]=text;
                p++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();//закрити файл
                }
            } catch (IOException e) {
            }
        }

        // marks

        file = new File("marks.txt");
        reader = null;
        p=0;
        try {
            reader = new BufferedReader(new FileReader(file));
            String text = null;

            while ((text = reader.readLine()) != null) {
                marks[p]= Integer.parseInt(text);
                p++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();//закрити файл
                }
            } catch (IOException e) {
            }
        }




        for (int i = 0; i <p; i++) {
            txt="";txt+=(i+1)+")";
            g.drawString(txt,405,140+20*i);
            txt="";txt+=spisok[i];
            g.drawString(txt,405+40,140+20*i);
            txt="";txt+=marks[i];
            g.drawString(txt,405+180,140+20*i);
        }

*/

    }

/*
    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }
*/

    public GUIproLib() {

        super("Практикум ПРО");
        addWindowListener(this);
        setLayout(null);
        setLocation(20,50);
        setSize(750,600);
        this.setResizable(false);

        show();
    }
}