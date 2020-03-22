package jchat;

import java.awt.EventQueue;

import javax.swing.JDialog;

public class Main {

	public static void main(String[] args) {
		ChatConnector connector = new ChatConnector("localhost", 2112);
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ChatScreen window = new ChatScreen(connector);

				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});

	}

}
