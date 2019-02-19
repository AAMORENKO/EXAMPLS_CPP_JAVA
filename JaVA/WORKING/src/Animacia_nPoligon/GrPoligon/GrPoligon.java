package GrPoligon;

import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;

public class GrPoligon extends Frame implements WindowListener {

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

        g.setColor(new Color(0x0B007A));
        String txt = " ";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 44));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 270, nf / 2 - 200);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO
        final double pi=3.1415926535897932384626433832795;

        double xf, yf, f;
        f = 0;
        int D=500; int n=15;
        int k=0;

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
            g.drawLine(x1,y1,x2,y2);
            //k++;
        }

        for (int i = 0; i <n ; i++) {
            for (int j = i; j <n ; j++) {
                g.drawLine(XA[i],YA[i],XA[j],YA[j]);
            }
        }


    }




    public GrPoligon() {
        super("Програма викреслює правильний многокутник");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}