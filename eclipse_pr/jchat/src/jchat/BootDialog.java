package jchat;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.JDialog;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class BootDialog{
	private String address;
	private int port;
    private JDialog dialog;
	private JFrame frame;
	private JFrame rootFrame;


	private JTextField addressTextInput;
	private JTextField portTextField;

	/**
	 * Create the application.
	 */
	public BootDialog(JFrame rootFrame) {
		this.rootFrame = rootFrame;
		initialize();
	
		
	}
	
	public String getAddress() {
		return address;
	}


	public int getPort() {
		return port;
	}
	
	public JFrame getFrame() {
		return frame;
	}
	
	void display() {
		dialog = new JDialog(rootFrame, "Address", true);
		dialog.setResizable(false);
		dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
		dialog.setContentPane(frame);
		dialog.setLocationRelativeTo(rootFrame);
		dialog.setVisible(true);
	}
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 289, 159);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("IP Address");
		lblNewLabel.setBounds(10, 27, 62, 14);
		frame.getContentPane().add(lblNewLabel);
		
		addressTextInput = new JTextField();
		addressTextInput.setBounds(10, 45, 151, 20);
		frame.getContentPane().add(addressTextInput);
		addressTextInput.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("Port Number");
		lblNewLabel_1.setBounds(171, 27, 89, 14);
		frame.getContentPane().add(lblNewLabel_1);
		
		portTextField = new JTextField();
		portTextField.setBounds(171, 45, 86, 20);
		frame.getContentPane().add(portTextField);
		portTextField.setColumns(10);
		 
		JButton btnNewButton = new JButton("Connect !");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					address = addressTextInput.getText();
					port = Integer.parseInt(portTextField.getText());
					frame.dispose();
				} catch (Exception e) {
					JOptionPane.showMessageDialog(frame, "Invalid port number", "Error", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		btnNewButton.setBounds(171, 76, 89, 23);
		frame.getContentPane().add(btnNewButton);
	}
}
