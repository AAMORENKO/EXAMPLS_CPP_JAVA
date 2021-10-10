Програма пошуку в квадратних матрицях A[9][9] і B[7][7]

Основний файл - Програма множення прямокутних матриць Моренко 10-Мі.docx
містить інформацію та лістинги усіх етапів

Посилання на відео - https://youtu.be/hWET0wPXuvc

Останній лістинг проєкту -

import org.w3c.dom.css.RGBColor;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;


public class MultiRectMatrixApp {

    public static void main(String[] args) throws FileNotFoundException {
        new GrMultiRectMatrixApp();
    }

    public static int rnd(int min,int max){
        return new Random().ints(min,max).iterator().nextInt();
    }

    public static class GrMultiRectMatrixApp extends Frame implements
            WindowListener {
        @Override
        public void windowOpened(WindowEvent e) {
        }
        @Override
        public void windowClosing(WindowEvent e) {
            dispose();
            System.exit(0);
        }
        @Override
        public void windowClosed(WindowEvent e) {
        }
        @Override
        public void windowIconified(WindowEvent e) {
        }
        @Override
        public void windowDeiconified(WindowEvent e) {
        }
        @Override
        public void windowActivated(WindowEvent e) {
        }@Override
        public void windowDeactivated(WindowEvent e) {
        }


        public int n=9;
        public int m=9;
        public int p=7;
        public int q=7;
        public int[][] A=new int[n][m];
        public int[][] B=new int[p][q];
        public int[][] C=new int[n][q];
        public String ms,t,z, text;
        public File af=new File("A.txt");
        public File bf=new File("B.txt");
        //public File cf=new File("C.txt");
        public File otf=new File("data.txt");
        public int RH,RW,minx,miny,maxx,maxy,cx,cy,dx,dy;
        public int x,y,x1,y1,x2,y2,x3,y3,x4,y4;
        public float wt=1.5f;
        public int acounter=0;
        public int bcounter=0;
        //public Scanner scana=new Scanner(af);

        public void paint(Graphics g){

            Dimension rc=getSize();
            Insets in=getInsets();
            RH=rc.width;
            RW=rc.height;
            minx=in.left;
            maxx=RH-in.right;
            miny=in.top;
            maxy=RW-in.bottom;
            cx=Math.abs(maxx-minx)/2;
            cy=Math.abs(maxy-miny)/2;
            dx=dy=25;

            g.setColor(new Color(4, 28, 237));
            text="Пошук в матрицях. Підготував: Моренко Олексій, 10-Мі клас";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,50,miny+35);
            ms=text;

            ms+="\n\nМатриця A[9][9]:\n";
            try {
                af.createNewFile();
                FileWriter writer=new FileWriter(af);text=n+"\n";
                //text+=m+"\n";
                acounter=0;
                for (int i = 0; i <n ; i++) {
                    for (int j = 0; j <m ; j++) {
                        A[i][j]=rnd(2000,2005);
                        if(A[i][j]==2004) acounter++;
                        text+=A[i][j]+" ";
                    }
                    text+="\n";
                }
                writer.write(text);
                writer.flush();
                writer.close();
                ms+=text;
            } catch (IOException e) {
                e.printStackTrace();
            }

            t="\nКількість максимальних елементів: "+acounter;
            ms+=t;
            ms+="\n\nМатриця B[7][7]:\n";
            try {
                bf.createNewFile();
                FileWriter writer=new FileWriter(bf);
                text=p+"\n";
                //text+=q+"\n";
                bcounter=0;
                for (int i = 0; i <p ; i++) {
                    for (int j = 0; j <q ; j++) {
                        B[i][j]=rnd(2000,2003);
                        if(B[i][j]==2000) bcounter++;
                        text+=B[i][j]+" ";
                    }
                    text+="\n";
                }
                writer.write(text);
                writer.flush();
                writer.close();
                ms+=text;
            } catch (IOException e) {
                e.printStackTrace();
            }


            z="\nКількість мінімальних елементів: "+bcounter;
            ms+=z;
            try {
                otf.createNewFile();
                FileWriter writer=new FileWriter(otf);
                writer.write(ms);
                writer.flush();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

/////////////////////////////////////////////////

            Graphics2D g2=(Graphics2D)g;
            g2.setStroke(new BasicStroke(wt));g.setColor(new Color(255, 51, 58));
            text="Матриця A[9][9]:";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,50,miny+60);


            g.setColor(new Color(107, 0, 229));
            dx=(maxx-minx)/(2*m);
            dy=(maxy-miny)/(2*n);
            x=minx+20; y=miny+75;
            for (int i = 0; i <=n ; i++) {
                g.drawLine(x,y+i*dy,x+maxx-401,y+i*dy);
            }
            for (int i = 0; i <=m ; i++) {
                g.drawLine(x+i*dx,y,x+i*dx,y+maxy-320);
            }

            g.setColor(new Color(0, 0, 0));
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,16));
            x=x+dx/2-17; y=y+dy/2+7;
            for (int i = 0; i <n ; i++) {
                for (int j = 0; j <m ; j++) {
                    text= String.valueOf(A[i][j]);
                    g.drawString(text,x+j*dx,y+i*dy);
                }
            }

////////////////////////////////////////////////////////////

            g.setColor(new Color(255, 51, 58));
            text="Матриця B[7][7]:";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+480,miny+60);
            g.setColor(new Color(107, 0, 229));
            dx=(maxx-minx)/(3*q);
            dy=(maxy-miny)/(2*p);
            x=minx+460; y=miny+75;
            for (int i = 0; i <=p ; i++) {
                g.drawLine(x,y+i*dy,x+maxx-538,y+i*dy);
            }
            for (int i = 0; i <=q ; i++) {
                g.drawLine(x+i*dx,y,x+i*dx,y+maxy-320);
            }
            g.setColor(new Color(0, 0, 0));
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,14));
            x=x+dx/2-15; y=y+dy/2+7;
            for (int i = 0; i <p ; i++) {
                for (int j = 0; j <q ; j++) {
                    text= String.valueOf(B[i][j]);
                    g.drawString(text,x+j*dx,y+i*dy);
                }
            }

/////////////////////////////////////////////////

            g.setColor(new Color(255, 51, 58));
            text="Кількість максимальних елементів";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+20,miny+380);
            text="в матриці A[9][9] дорівнює "+acounter;
            g.drawString(text,minx+20,miny+405);

///////////////////////////////////////////////////

            g.setColor(new Color(255, 51, 58));
            text="Кількість мінімальних елементів";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+440,miny+380);
            text="в матриці B[7][7] дорівнює "+bcounter;
            g.drawString(text,minx+440,miny+405);
        }

        public GrMultiRectMatrixApp() throws FileNotFoundException {
            super("Обробка даних матриць в графічному режимі: A[9][9],B[7][7]");
                    addWindowListener(this);
            setLayout(null);
            setLocation(80,80);
            setSize(800,600);
            this.setResizable(false);
            show();
        }
    }
}
