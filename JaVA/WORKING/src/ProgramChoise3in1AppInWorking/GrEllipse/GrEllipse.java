package GrEllipse;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

import static java.lang.Thread.sleep;
import static javax.swing.JFrame.EXIT_ON_CLOSE;

public class GrEllipse extends Frame implements WindowListener {
    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        this.dispose();
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

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }

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
        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;

        dx = Math.abs(maxX-minX) / 7;
        dy = Math.abs(maxY-minY) / 7;



        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO
        final double pi=3.1415926535897932384626433832795;

        Color[] c=new Color[8];

        c[0] = new Color(0x000000FF);
        c[1] = new Color(0x0000A5FF);
        c[2] = new Color(0x0000DDFF);
        c[3] = new Color(0x00008000);
        c[4] = new Color(0x00FFFF00);
        c[5] = new Color(0x00FF0000);
        c[6] = new Color(0x00D30094);
        c[7] = new Color(0xFFFFFF);

        int k=0;



        for (k = 0; k <7 ; k++)
        {
            int wleft = (int) (minX + k * dx/2.15f)+k*5+5;
            int wtop = (int) (minY + k * dy/2.15f)+5*k+5;
            int wright= maxX-k*dx-20;
            int wbootom = maxY-k*dy-40;
            g.setColor(c[k]);
            g.fillOval(wleft, wtop, wright, wbootom);
            //g.setColor(c[7]);
            //g.drawOval(wleft, wtop, wright, wbootom);
        }
    }


    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrEllipse() {
        super("Спектр у вигляді кругів.");
        addWindowListener(this);
        setLayout(null);
        setLocation(120,100);
        setSize(780,620);
        show();
        this.setResizable(false);
    }


}
