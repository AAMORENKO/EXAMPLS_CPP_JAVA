package GrFullStaticReport;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class GrFullStaticReport extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e) {};

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) {};
    public void windowIconified(WindowEvent e) {};
    public void windowDeiconified(WindowEvent e) {};
    public void windowActivated(WindowEvent e) {};
    public void windowDeactivated(WindowEvent e) {};

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;
        int x1, y1, x2, y2;
        int cr,cq,cb;
        int d;
        int cx, cy, dx, dy;
        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;


        /*
        g.setColor(new Color(0x8F46C8));
        String txt = "Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);
        */



        g.setColor(new Color(195,5,80));
        String txt = "Квадратна матриця з випадковими двоцифровими цілими числами:";
        g.setFont(new Font("Times New Roman", Font.BOLD, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 350, nf / 2 - 320);


        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO


        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));

        int poz,neg,min,max,sum,dob,p;

        int n=5;
        int [][] A=new int [n][n];
        int [] B=new int[n*n];

        int a=-99;
        int b=99;



        File nFile = new File("C:\\TEMP\\result.txt");
        try {
            nFile.createNewFile();
            FileWriter writer = new FileWriter(nFile);

            txt = "Квадратна матриця з випадковими двоцифровими цілими числами:";
            writer.write(txt+"\n");

            y1=100;
            dx=60; dy=40;
            for (int k = 0; k <n ; k++) {
                x1=80; txt="";
                for (int i = 0; i <n ; i++) {
                    do {
                        A[k][i] = rnd(a, b);
                    }while (Math.abs(A[k][i])<10||Math.abs(A[k][i])>99);
                    txt+=A[k][i];
                    if(k!=i) {
                        g.setColor(new Color(0,0,0));
                        g.drawString(txt, x1, y1);
                    }
                    else
                    {
                        g.setColor(new Color(182, 52, 234));
                        g.drawString(txt, x1, y1);
                    }
                    writer.write(txt);
                    if(A[k][i]<0) x1+=dx; else x1+=(dx+1.5);
                    txt="";
                }
                writer.write("\n");
                y1+=dy;
            }




            g.setColor(new Color(20, 177, 195));
            txt = "Обрані елементи квадратної матриці:";
            writer.write(txt+"\n");
            g.setFont(new Font("Times New Roman", Font.BOLD, 25));
            g.drawString(txt,40,300);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            y1=340;
            dx=60; dy=40;

            poz=neg=sum=p=0;
            dob=1;

            for (int k = 0; k <n ; k++)
            {
                x1=80; txt="";
                for (int i = 0; i <n ; i++)
                {
                    if(k==i) txt+=" * "; else txt+=A[k][i];
                    g.drawString(txt,x1,y1);
                    writer.write(txt);

                    if(A[k][i]<0) x1 += dx; else x1 += (dx + 1.5);
                    txt="";

                    if(k==i)
                    {
                        B[p]=A[k][i];
                        if(A[k][i]>0)
                        {
                            poz++;
                            sum+=A[k][i];
                        }
                        if(A[k][i]<0)
                        {
                            neg++;
                            dob *= A[k][i];
                        }
                        p++;
                    }
                }
                writer.write("\n");
                y1+=dy;
            }

            min=B[0];
            max=B[0];
            for (int k = 0; k <n; k++)
            {
                if (min > B[k]) min = B[k];
                if (max < B[k]) max = B[k];
            }

            x1=490; y1=340;
            g.setColor(new Color(10,150,80));
            txt = "Додатних: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=poz;
            g.drawString(txt,x1+2*dx+16,y1);
            writer.write(txt+"\n");

            x1=490-dx; y1+=dy;
            g.setColor(new Color(10,150,80));
            txt = "Сума додатних: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=sum;
            g.drawString(txt,x1+3*dx+15,y1);
            writer.write(txt+"\n");

            x1=490; y1+=dy;
            g.setColor(new Color(10,150,80));
            txt = "Від'ємних: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=neg;
            g.drawString(txt,x1+2*dx+16,y1);
            writer.write(txt+"\n");

            x1=475-dx; y1+=dy;
            g.setColor(new Color(10,150,80));
            txt = "Добуток від'ємних: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=dob;
            g.drawString(txt,x1+3*dx+26,y1);
            writer.write(txt+"\n");

            x1=455; y1+=dy;
            g.setColor(new Color(10,150,80));
            txt = "Мінімальний: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=min;
            g.drawString(txt,x1+2*dx+35,y1);
            writer.write(txt+"\n");

            x1=435; y1+=dy;
            g.setColor(new Color(10,150,80));
            txt = "Максимальний: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 22));
            g.drawString(txt,x1,y1);
            writer.write(txt);
            g.setColor(new Color(0,0,0));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
            txt=""; txt+=max;
            g.drawString(txt,x1+2*dx+60,y1);
            writer.write(txt+"\n");


            writer.flush();
            writer.close();

        } catch (IOException e) {
            e.printStackTrace();
        }





    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrFullStaticReport() {

        //super("Графічні примітиви.");
        super("Прикладне програмування");

        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(820,600);
        show();
    }
}