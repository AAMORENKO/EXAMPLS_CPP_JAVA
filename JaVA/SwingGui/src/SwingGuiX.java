import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class SwingGuiX extends JFrame {

    JButton button = new JButton("press");
    JTextField input = new JTextField("", 5);
    JLabel label = new JLabel("input: ");
    JRadioButton rad1 = new JRadioButton("Set this");
    JRadioButton rad2 = new JRadioButton("Set that");
    JCheckBox chek = new JCheckBox("Check", false);

    public SwingGuiX() {
        super("SwingGuiX");
        this.setBounds(200, 150, 300, 200);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 2, 2, 2));

        container.add(label);
        container.add(input);

        ButtonGroup group = new ButtonGroup();
        group.add(rad1);
        group.add(rad2);
        container.add(rad1);
        rad1.setSelected(true);
        container.add(rad2);
        container.add(chek);

        button.addActionListener(new ButtonEventList());
        container.add(button);

    }


    class ButtonEventList implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String ms = "";
            ms += "Press Button\n";
            ms += "This" + input.getText() + "\n";
            ms += (rad1.isSelected() ? "#1" : "#2") + " select\n";
            ms += (chek.isSelected() ? "Tr" : "Fl") + " on\n";
            JOptionPane.showMessageDialog(null, ms, "OutPut", JOptionPane.PLAIN_MESSAGE);
        }
    }



}