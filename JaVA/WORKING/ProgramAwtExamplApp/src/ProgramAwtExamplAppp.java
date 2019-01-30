   import java.awt.event.*;
        import java.awt.*;

class GrLibrary extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e){};
    public void windowClosing(WindowEvent e){
        dispose();
        System.exit(0);
    };
    public void windowClosed(WindowEvent e){};
    public void windowIconified(WindowEvent e){};
    public void windowDeiconified(WindowEvent e){};
    public void windowActivated(WindowEvent e){};
    public void windowDeactivated(WindowEvent e){};
    public void paint(Graphics g){
        Dimension rc=getSize();
        int RH=rc.width;
        int RW=rc.height;
        g.setColor(Color.white);

        Graphics2D g2=(Graphics2D) g;
        g2.setStroke(new BasicStroke(4.0f));

        int cx,cy,dx,dy;

        cx=RH/2; dx=RH/20;
        cy=RW/2; dy=RW/20;

        //TODO
        String txt="Ура! Перший крок зроблено! :)";
        g.setFont(new Font("Trebuchet Ms",Font.PLAIN,24));
        g.setColor(Color.BLUE);
        int n=g.getFontMetrics().stringWidth(txt);

        g.drawString(txt,n/2-150,n/2-100);

        g.setColor(Color.red);
        for (int i = 1; i <45 ; i++) {
            g.drawLine(cx-100,cy,cx+200,cy+250-i*10);
        }
        g.setColor(Color.GREEN);
        g.fillRect(40,100,5*dx,100+9*dy);

        g.setColor(Color.CYAN);
        g.drawRect(30,90,5*dx+20,120+9*dy);

        g.setColor(Color.WHITE);
        g.fillOval(55,120,4*dx,100+5*dy);

        g.setColor(Color.BLACK);
        g.drawOval(45,110,5*dx-10,120+5*dy);

/*        for (int i = 0; i <100 ; i++) {
            double x1=Math.random()%100;
            double y1=Math.random()%200;
            double x2=Math.random()%100;
            double y2=Math.random()%200;
            g..drawRect(x1,y1,x2,y2);
        }
*/

    }
    public GrLibrary(){
        super("Графічні примітиви. Малюємо!");
        addWindowListener(this);
        setSize(640,480);
        show();
    }
    public static void main(String[] args) {
        new GrLibrary();
    }
}

