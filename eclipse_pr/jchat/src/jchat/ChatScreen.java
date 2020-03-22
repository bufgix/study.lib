package jchat;


import javax.swing.JFrame;

public class ChatScreen {

	private JFrame frame;
	private ChatConnector connector;
	
	public JFrame getFrame() {
		return frame;
	}

	/**
	 * Create the application.
	 */
	public ChatScreen(ChatConnector connector) {
		this.connector = connector;
		initialize();
		frame.setVisible(true);
		BootDialog bDialog = new BootDialog(frame);
		bDialog.display();
		System.out.println(bDialog.getAddress());
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
	}

}
