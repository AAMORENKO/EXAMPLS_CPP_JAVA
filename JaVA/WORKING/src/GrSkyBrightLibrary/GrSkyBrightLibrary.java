package GrSkyBrightLibrary;
import java.util.Random;
import java.awt.*;
import java.awt.event.*;
import java.sql.Time;

public class GrSkyBrightLibrary extends Frame implements WindowListener {

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
        int maxX = RH;
        int minY = in.top;
        int maxY = RW;
        int x1, y1, x2, y2;
        int cr, cq, cb;
        int d;
        int cx, cy, dx, dy;
        float wdk = 3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        g.setColor(new Color(0, 0, 0));
        g.fillRect(minX, minY, maxX, maxY);

        g.setColor(new Color(0xFFFFFF));
        String txt = "Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        int n = 5000;
        // TO DO
        int[] XX = new int[n];
        int[] YY = new int[n];


        for (int k = 0; k < n; k++) {
            XX[k] = rnd(minX + 30, maxX - 30);
            YY[k] = rnd(minY + 50, maxY - 30);
        }

        for (int j = 0; j <5; j++) {
            n = 50;
            int p = 0;
            g.setColor(new Color(255, 255, 255));
            do {
                g2.setStroke(new BasicStroke(10.0f - p));
                d = 4;
                for (int k = 0; k < n; k++) {
                    g.fillOval(XX[k], YY[k], d, d);
                    try {
                        Thread.sleep(50);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    d += 0.75;
                }
                p++;
                d = 4;
            } while (p > 25);

            p = 0;
            g.setColor(new Color(0, 0, 0));
            do {
                g2.setStroke(new BasicStroke(10.0f - p));
                d = 4;
                for (int k = 0; k < n; k++) {
                    g.fillOval(XX[k], YY[k], d, d);
                    try {
                        Thread.sleep(50);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    d += 0.5;
                }
                p++;
                d = 4;
            } while (p > 25);
        }
    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrSkyBrightLibrary() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}