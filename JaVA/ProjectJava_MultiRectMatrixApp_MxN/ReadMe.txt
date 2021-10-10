Програма множення прамокутних матриць
A[n][m] x B[p][q] = C[n][q]

Основний файл - Програма множення прямокутних матриць Моренко 11-Мі.docx
містить інформацію та лістинги усіх етапів

Посилання на відео - https://youtu.be/Ni0SQu_4DOc

Останній лістинг проєкту -



import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;




public class MultiRectMatrixApp {

    public static void main(String[] args) throws FileNotFoundException {
        new GrMultiRectMatrixApp();
    }
///////////////////////////////////////////////////////////////////////////////

    public static int rnd(int min,int max){
        return new Random().ints(min,max).iterator().nextInt();
    }
///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

        public int n=8;
        public int m=11;
        public int p=11;
        public int q=5;
        public int[][] A=new int[n][m];
        public int[][] B=new int[p][q];
        public int[][] C=new int[n][q];
        public String ms,t,z, text;
        public File af=new File("A.txt");
        public File bf=new File("B.txt");
        public File cf=new File("C.txt");
        public File otf=new File("data.txt");
        public int RH,RW,minx,miny,maxx,maxy,cx,cy,dx,dy;
        public int x,y,x1,y1,x2,y2,x3,y3,x4,y4;
        public float wt=1.5f;

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
            text="Множення матриць. Підготував: Моренко Олексій, 11-Мі клас";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,50,miny+35);

///////////////////////////////////////////////////////////////////////////////

            ms=text;
            ms+="\nМатриця A[n][m]:\n";
            try {
                af.createNewFile();
                FileWriter writer=new FileWriter(af);
                text=n+"\n";
                text+=m+"\n";
                for (int i = 0; i <n ; i++) {
                    for (int j = 0; j <m ; j++) {A[i][j]=rnd(1,9);
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

///////////////////////////////////////////////////////////////////////////////

            ms+="\nМатриця B[p][q]:\n";
            try {
                bf.createNewFile();
                FileWriter writer=new FileWriter(bf);
                text=p+"\n";
                text+=q+"\n";
                for (int i = 0; i <p ; i++) {
                    for (int j = 0; j <q ; j++) {
                        B[i][j]=rnd(1,9);
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

///////////////////////////////////////////////////////////////////////////////

            ms+="\nМатриця C[n][q]:\n";
            try {
                cf.createNewFile();
                FileWriter writer=new FileWriter(cf);
                text=n+"\n";
                text+=q;
                for (int i = 0; i < n; i++) {
                    text += "\n";
                    for (int j = 0; j < q; j++) {
                        C[i][j] = 0;
                        for (int k = 0; k < m; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                        text += C[i][j] + " ";
                    } ;
                }
                writer.write(text);
                writer.flush();
                writer.close();
                ms+=text;
            } catch (IOException e) {
                e.printStackTrace();
            }

///////////////////////////////////////////////////////////////////////////////

            try {
                otf.createNewFile();
                FileWriter writer=new FileWriter(otf);
                writer.write(ms);
                writer.flush();writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

///////////////////////////////////////////////////////////////////////////////

            Graphics2D g2=(Graphics2D)g;
            g2.setStroke(new BasicStroke(wt));
            g.setColor(new Color(157, 35, 57));
            text="Матриця A[8][11]:";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+50,miny+60);
            g.setColor(new Color(0,0,255));
            dx= (int) ((maxx-minx)/(2*m));
            dy= (int) ((maxy-miny-100)/(2*n));
            x=minx+10; y=miny+70;
            for (int i = 0; i <=n ; i++) {
                g.drawLine(x,y+i*dy,x+maxx-402,y+i*dy);
            }
            for (int i = 0; i <=m ; i++) {
                g.drawLine(x+i*dx,y,x+i*dx,y+maxy-365);
            }
            g.setColor(new Color(0,0, 0));
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,20));
            x=x+dx/2-10; y=y+dy/2+5;
            for (int i = 0; i <n ; i++) {
                for (int j = 0; j <m ; j++) {
                    text= String.valueOf(A[i][j]);
                    g.drawString(text,x+j*dx,y+i*dy);
                }
            }

///////////////////////////////////////////////////////////////////////////////

            g.setColor(new Color(157, 35, 57));
            text="Матриця B[11][5]:";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+500,miny+60);
            g.setColor(new Color(0,0,255));
            dx= (int) ((maxx-minx)/(3*q));
            dy= (int) ((maxy-miny-100)/(2*p));
            x=minx+480; y=miny+70;
            for (int i = 0; i <=p ; i++) {
                g.drawLine(x,y+i*dy,x+maxx-537,y+i*dy);
            }
            for (int i = 0; i <=q ; i++) {
                g.drawLine(x+i*dx,y,x+i*dx,y+maxy-365);
            }
            g.setColor(new Color(0,0, 0));
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,20));
            x=x+dx/2-10; y=y+dy/2+7;
            for (int i = 0; i <p ; i++) {
                for (int j = 0; j <q ; j++) {
                    text= String.valueOf(B[i][j]);
                    g.drawString(text,x+j*dx,y+i*dy);
                }
            }

///////////////////////////////////////////////////////////////////////////////

            g.setColor(new Color(157, 35, 57));
            text="Результат множення матриць - Матриця C[8][5]:";
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,21));
            g.drawString(text,minx+50,miny+325);
            g.setColor(new Color(0,0,255));
            dx= (int) ((maxx-minx)/(2*q));
            dy= (int) ((maxy-miny-100)/(2*n));
            x=minx+10; y=miny+335;
            for (int i = 0; i <=n ; i++) {
                g.drawLine(x,y+i*dy,x+maxx-402,y+i*dy);
            }
            for (int i = 0; i <=q ; i++) {
                g.drawLine(x+i*dx,y,x+i*dx,y+maxy-365);
            }
            g.setColor(new Color(0,0, 0));
            g.setFont(new Font("Trebuchet Ms",Font.BOLD,20));
            x=x+dx/2-10; y=y+dy/2+7;
            for (int i = 0; i <n ; i++) {
                for (int j = 0; j <q ; j++) {
                    text= String.valueOf(C[i][j]);
                    g.drawString(text,x+j*dx,y+i*dy);
                }
            }
        }

///////////////////////////////////////////////////////////////////////////////


        public GrMultiRectMatrixApp() throws FileNotFoundException {
            super("Множення матриць в графічному режимі: A[8][11]xB[11][5]=C[8][5]");
            addWindowListener(this);
            setLayout(null);
            setLocation(80,80);
            setSize(800,600);
            this.setResizable(false);
            show();
        }
    }
}
