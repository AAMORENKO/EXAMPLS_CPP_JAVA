package GrAnimacia;

import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;

public class GrAnimacia extends Frame implements WindowListener {

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
        String txt = "Зона переміщення об'єктів";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 44));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 270, nf / 2 - 200);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO
        g.setColor(new Color(0,0,0));
        d=100;
        x1=minX; y1=minY+d;
        x2=maxX; y2=maxY;
        g.fillRect(x1,y1,x2,y2);

        final double pi=3.1415926535897932384626433832795;
        double a,b,xf,yf;

        a=-2*pi; b=2*pi;

        for (x1 = minX-50; x1 <maxX ; x1+=7)
        {
            xf=a+x1*(b-a)/maxX;
            yf=2.5*Math.sin(xf);
            y1=(int)(yf*maxX/(b-a));
            y1=maxY/2-y1+50;

            g.setColor(new Color(255, 177, 30));
            g.drawOval(x1,y1,d/3,d/3);
            g.setColor(new Color(255, 248, 68));
            g.fillOval(x1+2,y1+2,d/3-2,d/3-2);

            try {
                sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            xf=a+x1*(b-a)/maxX;
            yf=Math.cos(2*xf);
            y1=(int)(yf*maxX/(b-a));
            y1=maxY/2-y1+50;

            g.setColor(new Color(154, 15, 255));
            g.drawOval(x1,y1,d/3,d/3);
            g.setColor(new Color(81, 188, 255));
            g.fillOval(x1+2,y1+2,d/3-2,d/3-2);

            try {
                sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }







        }



    }

    public GrAnimacia() {
        super("Програма рухомих об'єктів");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}