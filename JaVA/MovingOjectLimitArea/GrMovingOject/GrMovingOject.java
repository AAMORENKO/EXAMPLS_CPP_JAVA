package GrMovingOject;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

import static java.lang.Thread.sleep;

public class GrMovingOject extends Frame implements WindowListener {

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
        String txt;
        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        //g.setColor(new Color(0x0B007A));
        txt = "";
        //g.setFont(new Font("Trebuchet Ms", Font.BOLD, 44));
        //int nf = g.getFontMetrics().stringWidth(txt);
        //g.drawString(txt, nf / 2 - 270, nf / 2 - 200);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO
        final double pi=3.1415926535897932384626433832795;

        double xf, yf, f;
        f = 0;
        int D=400;
        int n=60;
        int k=0;
        int mtime=20;
        d=30;

        int [] XA=new int [360];
        int [] YA=new int [360];

        while (k<=n)
        {
            xf = D / 2 * Math.cos(f);
            yf = D / 2 * Math.sin(f);
            x1=(int)xf+cx;
            y1=(int)yf+cy+30;
            XA[k]=x1;
            YA[k]=y1;
            k++;
            f += (2*pi/n);
            xf = D / 2 * Math.cos(f);
            yf = D / 2 * Math.sin(f);
            x2=(int)xf+cx;
            y2=(int)yf+cy+30;
            XA[k]=x2;
            YA[k]=y2;
            //g.drawLine(x1,y1,x2,y2);
            //k++;
        }

// -------------------------------------------------------------------
        g.setColor(new Color(0,0,0));
        g.fillRect(minX,minY,maxX,maxY);
// -------------------------------------------------------------------
        for (k = 0; k <n ; k++)
        {
            g.setColor(new Color(52,200,142));
            g.fillOval(XA[k],YA[k],d,d);
            g.drawLine(XA[k],YA[k],cx,cy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            g.setColor(new Color(0,0,0));
            g.fillOval(XA[k],YA[k],d,d);
            g.drawLine(XA[k],YA[k],cx,cy);
        }
// -------------------------------------------------------------------
        for (k = 0; k <n ; k++)
        {
            g.setColor(new Color(240,233,41));
            g.fillRect(XA[k],YA[k],d,d);
            g.drawLine(XA[k],YA[k],cx,cy);
            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.setColor(new Color(0,0,0));
            g.fillRect(XA[k],YA[k],d,d);
            g.drawLine(XA[k],YA[k],cx,cy);
        }
// -------------------------------------------------------------------
        for (int i = 0; i <512 ; i++) {
            g.setColor(new Color(rnd(0,255),rnd(0,255),rnd(0,255)));
            g.setFont(new Font("Trebuchet Ms", Font.BOLD, rnd(28,72)));
            txt = "";
            int digit=rnd(10,99);
            txt+=digit;
            g.drawString(txt,rnd(minX+50,Math.abs(maxX-100)),rnd(minY+50,Math.abs(maxY-30)));
            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

// -------------------------------------------------------------------
        g.setColor(new Color(0,0,0));
        g.fillRect(minX,minY,maxX,maxY);
// -------------------------------------------------------------------

        int bx,ex,by,ey;
        bx=x1=155; by=y1=55;
        ex=x2=490; ey=y2=490;
        g.setColor(new Color(240,233,41));
        g.drawRect(x1-20,y1-15,x2+50,y2+50);
        dx=10; dy=10;

        x1=bx+ex/2; y1=by;
        while(x1<ex+bx)
        {
            g.setColor(new Color(240,233,41));
            g.fillRect(x1,y1,d,d);

            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.setColor(new Color(0, 0, 0));
            g.fillRect(x1,y1,d,d);
            x1+=dx; y1+=dy;
        }

        x1=ex+bx; y1=by+ey/2;
        while(x1>bx+ex/2)
        {
            g.setColor(new Color(240,233,41));
            g.fillRect(x1,y1,d,d);

            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.setColor(new Color(0, 0, 0));
            g.fillRect(x1,y1,d,d);
            x1-=dx; y1+=dy;
        }

        x1=bx+ex/2; y1=ey+3*dy;
        while(x1>bx-2*dx)
        {
            g.setColor(new Color(240,233,41));
            g.fillRect(x1,y1,d,d);

            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.setColor(new Color(0, 0, 0));
            g.fillRect(x1,y1,d,d);
            x1-=dx; y1-=dy;
        }

        x1=bx-dx; y1=by+ey/2-2*dy;
        while(x1<bx+ex/2-dx)
        {
            g.setColor(new Color(240,233,41));
            g.fillRect(x1,y1,d,d);

            try {
                sleep(mtime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            g.setColor(new Color(0, 0, 0));
            g.fillRect(x1,y1,d,d);
            x1+=dx; y1-=dy;
        }


    }


    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }


    public GrMovingOject() {
        super("Програма викреслює правильний многокутник");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}
