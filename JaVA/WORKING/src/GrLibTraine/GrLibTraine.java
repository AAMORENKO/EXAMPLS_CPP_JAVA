package GrLibTraine;

import java.awt.*;
import java.awt.event.*;

public class GrLibTraine extends Frame implements WindowListener {

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
        g.setColor(new Color(0,0,0));
        wdk=1.5f;
        g2.setStroke(new BasicStroke(wdk));


        cx=RH/2;
        cy=RW/2;

        dx = cx / 8;
        dy = (int) (cy / 6.5);

        x1 = cx;
        y1 = cy-4*dy;

        g.drawLine(cx + 7 * dx, cy - dy * 4,cx + 7 * dx, cy - dy * 4);
        g.drawLine(cx + 7 * dx, cy - dy * 4,cx + 1 * dx, cy - dy * 4);
        g.drawLine(cx + 1 * dx, cy - dy * 4,cx + 1 * dx, cy - dy * 2);
        g.drawLine(cx + 1 * dx, cy - dy * 2,cx - 3 * dx, cy - dy * 2);
        g.drawLine(cx - 3 * dx, cy - dy * 2,cx - 3 * dx, cy - dy * 5);
        g.drawLine(cx - 3 * dx, cy - dy * 5,cx - 4 * dx, cy - dy * 5);
        g.drawLine(cx - 4 * dx, cy - dy * 5,cx - 4 * dx, cy - dy * 2);
        g.drawLine(cx - 4 * dx, cy - dy * 2,cx - 5 * dx, cy - dy * 2);
        g.drawLine(cx - 5 * dx, cy - dy * 2,cx - 5 * dx, cy + dy * 1);
        g.drawLine(cx - 5 * dx, cy + dy * 1,cx - 6 * dx, cy + dy * 1);
        g.drawLine(cx - 6 * dx, cy + dy * 1,cx - 6 * dx, cy + dy * 2);
        g.drawLine(cx - 6 * dx, cy + dy * 2,cx + 6 * dx, cy + dy * 2);
        g.drawLine(cx + 6 * dx, cy + dy * 2,cx + 6 * dx, cy - dy * 3);
        g.drawLine(cx + 6 * dx, cy - dy * 3,cx + 7 * dx, cy - dy * 3);
        g.drawLine(cx + 7 * dx, cy - dy * 3,cx + 7 * dx, cy - dy * 4);




        g.drawLine(cx + 2 * dx, cy - dy * 3,cx + 2 * dx,cy - dy * 3);
        g.drawLine(cx + 2 * dx, cy - dy * 3,cx + 2 * dx, cy - dy * 1);
        g.drawLine(cx + 2 * dx, cy - dy * 1,cx + 4 * dx, cy - dy * 1);
        g.drawLine(cx + 4 * dx, cy - dy * 1,cx + 4 * dx, cy - dy * 3);
        g.drawLine(cx + 4 * dx, cy - dy * 3,cx + 2 * dx, cy - dy * 3);


        g.setColor(new Color(255,255,255));
        g.fillOval(cx - dx * 4, cy + 1 * dy, dx * 2, 2 * dy);
        g.fillOval(cx - dx * 1, cy + 1 * dy, dx * 2, 2 * dy);
        g.fillOval(cx + dx * 2, cy + 1 * dy, dx * 2, 2 * dy);

        g.setColor(new Color(0,0,0));
        g.drawOval(cx - dx * 4, cy + 1 * dy, dx * 2, 2 * dy);
        g.drawOval(cx - dx * 1, cy + 1 * dy, dx * 2, 2 * dy);
        g.drawOval(cx + dx * 2, cy + 1 * dy, dx * 2, 2 * dy);
    }

    public GrLibTraine() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}