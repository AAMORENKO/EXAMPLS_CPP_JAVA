package GrLibrary;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class GrLibrary extends Frame implements WindowListener {

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

        int n=5;
        int [][] A=new int [n][n];

        int a=-99;
        int b=99;

        y1=100;
        dx=60; dy=40;
        for (int k = 0; k <n ; k++) {
            x1=80; txt="";
            for (int i = 0; i <n ; i++) {
                do {
                    A[k][i] = rnd(a, b);
                }while (Math.abs(A[k][i])<10||Math.abs(A[k][i])>99);
                txt+=A[k][i];
                g.drawString(txt,x1,y1);
                if(A[k][i]<0) x1+=dx; else x1+=(dx+1.5);
                txt="";
            }
            y1+=dy;
        }


        int poz,neg,min,max,sum,dob;

        g.setColor(new Color(195,5,80));
        txt = "Обрані елементи квадратної матриці:";
        g.setFont(new Font("Times New Roman", Font.BOLD, 25));
        g.drawString(txt,40,300);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        y1=340;
        dx=60; dy=40;

        poz=neg=sum=0;
        dob=1;

        for (int k = 0; k <n ; k++)
        {
            x1=80; txt="";
            for (int i = 0; i <n ; i++)
            {
                if(k==i) txt+=" * "; else txt+=A[k][i];
                g.drawString(txt,x1,y1);
                if(A[k][i]<0)
                {
                    x1 += dx;
                }
                else {
                    x1 += (dx + 1.5);
                }
                txt="";
            }
            y1+=dy;
        }

        min=A[0][0];
        max=A[0][0];

        x1=460; y1=340;
        g.setColor(new Color(10,150,80));
        txt = "Додатних: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=poz;
        g.drawString(txt,x1+2*dx+16,y1);

        x1=460-dx; y1+=dy;
        g.setColor(new Color(10,150,80));
        txt = "Сума додатних: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=sum;
        g.drawString(txt,x1+3*dx+15,y1);

        x1=460; y1+=dy;
        g.setColor(new Color(10,150,80));
        txt = "Від'ємних: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=neg;
        g.drawString(txt,x1+2*dx+16,y1);

        x1=445-dx; y1+=dy;
        g.setColor(new Color(10,150,80));
        txt = "Добуток від'ємних: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=dob;
        g.drawString(txt,x1+3*dx+26,y1);

        x1=425; y1+=dy;
        g.setColor(new Color(10,150,80));
        txt = "Мінімальний: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=min;
        g.drawString(txt,x1+2*dx+35,y1);

        x1=405; y1+=dy;
        g.setColor(new Color(10,150,80));
        txt = "Максимальний: ";
        g.setFont(new Font("Times New Roman", Font.BOLD, 22));
        g.drawString(txt,x1,y1);
        g.setColor(new Color(0,0,0));
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));
        txt=""; txt+=max;
        g.drawString(txt,x1+2*dx+50,y1);

    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrLibrary() {
        super("Прикладне програмування");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}