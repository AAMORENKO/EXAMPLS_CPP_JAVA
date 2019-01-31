import java.awt.event.*;
import java.awt.*;

class GrLibrary extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e) {
    }

    ;

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    }

    ;

    public void windowClosed(WindowEvent e) {
    }

    ;

    public void windowIconified(WindowEvent e) {
    }

    ;

    public void windowDeiconified(WindowEvent e) {
    }

    ;

    public void windowActivated(WindowEvent e) {
    }

    ;

    public void windowDeactivated(WindowEvent e) {
    }

    ;

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        int cx, cy, dx, dy;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        g.setColor(new Color(0x00D30094));
        String txt = "Програмування графічними примітивами: ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);

        g.setColor(new Color(0x081F08));
        int x1, y1, x2, y2, k, i;

        // TO DO

        Graphics2D g2=(Graphics2D) g;
        g2.setStroke(new BasicStroke(3.0f));

        x1=90; y1=90; int d=120;
        dx=dy=115;
/*
        for (int j = 0; j <30 ; j++) {
            g.setColor(new Color(0xD56D10));
            g.drawRect(x1+j*dx,y1+j*dy,d-j*dx,d-j*dx);
            g.setColor(new Color(0x3CD037));
            g.drawOval(x1+j*dx,y1+j*dy,d-j*dx,d-j*dx);
            d-=dx;
        }

        for (int j = 0; j <4; j++) {

            for (int l = 0; l <5; l++) {
                g.drawOval(x1+l*dx,y1,d,d);
            }
            y1+=dy;
        }
*/
        x1=90; y1=90; d=120;
        for (int j = 0; j <3; j++) {
            x1=90;
            for (int l = 0; l <4; l++) {
                g.drawRect(x1,y1,d,d);
                x1+=(d+10);
            }
            y1+=(dy+20);
        }

        x1=150; y1=150; d=120;
        for (int j = 0; j <2; j++) {
            x1=150;
            for (int l = 0; l <3; l++) {
                g.drawRect(x1,y1,d,d);
                x1+=(d+10);
            }
            y1+=(dy+20);
        }

    }

    public GrLibrary() {
        super("Графічні примітиви.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120, 100);
        setSize(800, 600);
        show();
    }

    public static void main(String[] args) {
        new GrLibrary();
    }

}