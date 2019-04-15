package GUIproLib;

import java.io.File;
import java.nio.CharBuffer;
import java.sql.Struct;
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

        x=60; y=45; dy=20;

        String txt = "Перший файл. Pадіуси кіл:";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 16));
        g.setColor(new Color(0, 0, 0));
        g.drawString(txt, x, y);

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
            g.drawString(String.valueOf(list.get(i)),x,y+35+i*dy);
            dlina[i]=2*pi*radius[i];
            ploscha[i]=pi*radius[i]*radius[i];
        }

        txt="Другий файл:";
        g.drawString(txt,x,y+35+(p+1)*dy);

        txt="radius     dlina      ploschad";
        g.drawString(txt,x+60,y+35+(p+3)*dy);
        int k=0;
        txt="";
        y+=40;
        for (int i = 0; i <p; i++) {
            if(dlina[i]>7 && dlina[i]<10)
            {
                g.drawString(String.valueOf(radius[i]),x+60,4*y+60+k*dy);
                g.drawString(String.valueOf(dlina[i]),x+130,4*y+60+k*dy);
                g.setColor(new Color(255, 255, 255));
                g.fillRect(x+172,4*y+60+k*dy-16,400,40);
                g.setColor(new Color(0, 0, 0));
                g.drawString(String.valueOf(ploscha[i]),x+200,4*y+60+k*dy);
                g.setColor(new Color(255, 255, 255));
                g.fillRect(x+242,4*y+60+k*dy-16,400,40);
                g.setColor(new Color(0, 0, 0));

                ms += String.valueOf(radius[i]);
                ms += "\t\t";
                ms += String.valueOf(dlina[i]);
                ms += "\t\t";
                ms += String.valueOf(ploscha[i]);
                ms += "\n";

                k++;
            }
        }


        x=420; y1=105; y=45;

        txt="Результати перевірки:";
        g.drawString(txt,x,y);
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

        //виведення результатів розподілу даних в таблицях
        for (int i = 0; i <p; i++) {
            txt="";txt+=(i+1)+")";
            g.drawString(txt,x-15,y+35+dy*i);
            txt="";txt+=spisok[i];
            g.drawString(txt,x+35,y+35+dy*i);
            txt="";txt+=marks[i];
            g.drawString(txt,x+165,y+35+dy*i);
        }


        x=405; y=30;

        double sr, sum;
        sr = sum = 0; // обчислення середнього балу
        for (k = 0; k < p; k++)
        {
            sum += marks[k];
        }
        sr = sum / p;
        txt=""; txt+="середнiй бал оцiнок: ";
        txt+=sr;
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+dy*p+55);

        int max = marks[0];
        int min = marks[0];

        for (int i = 1; i < p; i++)// пошук максимального і мінімального балів
        {
            if (marks[i] > max) max = marks[i];
            if (marks[i] < min) min = marks[i];
        }

        txt=""; txt+="максимальний бал: ";txt+=max;
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+dy*p+75);
        txt=""; txt+="мінімальний бал: ";txt+=min;
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+dy*p+95);


        // вибірка учнів
        txt=""; txt+="прiзвища учнiв з максимальним балом: ";
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+dy*p+115);
        k=0;
        for (int t = 0; t < p; t++)
        {
            if (marks[t] > 9) {
                g.drawString(spisok[t],x+120*k,y+135+dy*p);
                ms+=spisok[t]+", ";
                k++;
            }
        }
        // вибірка учнів
        txt=""; txt+="прiзвища учнiв з мiнiмальним балом: ";
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+155+dy*p);
        k=0;
        for (int i = 0; i < p; i++)
        {
            if (marks[i] < 4) {
                g.drawString(spisok[i],x+k*120,y+175+dy*p);
                ms+=spisok[i]+", ";
                k++;
            }
        }

        int count = 0;
        for (k = 0; k < p; k++)// вибірка учнів
        {
            if (marks[k] > 9) count++;
        }
        txt=""; txt+="кiлькiсть учнiв, що вчаться на 10 балiв i вище: ";txt+=count;
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+195+dy*p);

        count = 0;
        for (k = 0; k < p; k++)// вибірка учнів
        {
            if (marks[k] < 4) count++;
        }
        txt=""; txt+="кiлькiсть учнiв, що мають 3 бали i нижче: ";txt+=count;
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+215+dy*p);

        // створюю структурний список та сортую його за абеткою

        List<String> sps = new ArrayList<String>();
        for (int i = 0; i <p; i++) {
            sps.add(spisok[i]+" "+marks[i]);
        }

        txt=""; txt+="список учнiв з їхнiми балами за абеткою: ";
        ms+="\n";
        ms+=txt;
        g.drawString(txt, x,y+235+dy*p);

        //сортування списку за абеткою
        String[] array=sps.toArray(new String[sps.size()]);
        Arrays.sort(array);


        for (k = 0; k < p; k++)//виведення результатів сортування
        {
            txt="";txt+=(k+1)+")  ";txt+=array[k];
            ms+="\n";
            ms+=txt;
            g.drawString(txt,x,y+465+dy*k);
        }


        // шукаємо матеріали на www.github.com/aamorenko

        //Запис до іншого файлу ....

        File wfile = new File("result.txt");
        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter(wfile));
            writer.write(ms);
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

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
        setLocation(100,30);
        setSize(850,700);
        this.setResizable(false);

        show();
    }
}