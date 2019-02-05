package GrPaintLibrary;

import java.util.Random;

import java.awt.*;
import java.awt.event.*;

public class GrPaintLibrary extends Frame implements WindowListener {

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

        g.setColor(new Color(0x8F46C8));
        String txt = "Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO
        for (int i = 0; i <1000 ; i++) {
            cr=rnd(0,255);
            cq=rnd(0,255);
            cb=rnd(0,255);
            g.setColor(new Color(cr,cq,cb));
            g2.setStroke(new BasicStroke(rnd(2,28)));

            x1=rnd(minX+20,maxX-120);
            y1=rnd(minY+50,maxY-150);
            d=rnd(20,120);

            g.fillOval(x1,y1,d,d);

            cr=rnd(0,255);
            cq=rnd(0,255);
            cb=rnd(0,255);
            g.setColor(new Color(cr,cq,cb));
            g2.setStroke(new BasicStroke(rnd(2,28)));

            x1=rnd(minX+20,maxX-120);
            y1=rnd(minY+50,maxY-150);
            d=rnd(20,120);

            g.drawOval(x1,y1,d,d);

            cr=rnd(0,255);
            cq=rnd(0,255);
            cb=rnd(0,255);
            g.setColor(new Color(cr,cq,cb));
            g2.setStroke(new BasicStroke(rnd(2,28)));

            x1=rnd(minX+20,maxX-120);
            y1=rnd(minY+50,maxY-150);
            d=rnd(20,120);

            g.drawRect(x1,y1,d,d);

            cr=rnd(0,255);
            cq=rnd(0,255);
            cb=rnd(0,255);
            g.setColor(new Color(cr,cq,cb));
            g2.setStroke(new BasicStroke(rnd(2,28)));

            x1=rnd(minX+20,maxX-120);
            y1=rnd(minY+50,maxY-150);
            d=rnd(20,120);

            g.fillRect(x1,y1,d,d);
        }
    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrPaintLibrary() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}