package GrMovingObject;

import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;


public class GrMovingObject extends Frame implements WindowListener {

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
        int bx,ex,by,ey;

        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;
/*
        g.setColor(new Color(0x8F46C8));
        String txt = " ";
        g.setFont(new Font("Trebuchet Ms", Font.PLAIN, 24));
        int nf = g.getFontMetrics().stringWidth(txt);
        g.drawString(txt, nf / 2 - 220, nf / 2 - 180);
*/
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO

        int mtime=80;

        g.setColor(new Color(0,0,0));
        g.fillRect(minX,minY,maxX,maxY);

        g.setColor(new Color(255, 177, 30));
        d=600;
        x1=cx-dx*4+20;
        y1=cy-4*dy;
        x2=x1+d;
        y2=y1+d-30;
        g.drawRect(x1,y1,x2,y2);

        bx=x1+dx/2;
        ex=x2-10;
        by=y1+10;
        ey=y2-10;

        //g.drawRect(bx,by,ex,ey);
        dx=dy=45;

        for (int i = 0; i <100 ; i++) {
            x1 = bx;
            y1 = by;
            while (x1 <= ex + dx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                //y1+=dy;
            }

            x1 = ex + dx;
            y1 = by;
            while (y1 <= ey) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 += dy;
            }

            x1 = ex;
            y1 = ey;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }

            x1 = bx;
            y1 = ey;
            while (y1 >= by) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 -= dy;
            }

            x1 = bx;
            y1 = by;
            while (x1 <= ex) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                y1 += dy;
            }

            x1 = ex;
            y1 = ey;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }

            x1 = bx;
            y1 = ey;
            while (x1 <= ex) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                y1 -= dy;
            }

            x1 = ex;
            y1 = by;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }
        }

    }

    public GrMovingObject() {
        super("Рухомі об'єкти");
        addWindowListener(this);
        setLayout(null);
        setLocation(100,20);
        setSize(900,700);
        show();
    }
}