package view;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;

class ViewPanel extends JPanel implements Observer {

	private ViewFrame viewFrame;
	private static final long serialVersionUID	= -998294702363713521L;

	private Image circuit;
	private Image voiture;
	private Image compteur;
	private Image trajet;
	private Image distance2;
	private Image parkingYes;
	private Image parkingNo;
	private Font police;
	private boolean observerSet = false;

	ViewPanel(final ViewFrame viewFrame) {

		this.setViewFrame(viewFrame);
		setObservateur();
		try {
			circuit = ImageIO.read(new File("Circuit.png"));
			voiture = ImageIO.read(new File("Voiture.png"));
			compteur = ImageIO.read(new File("Compteur.png"));
			trajet = ImageIO.read(new File("Trajet.png"));
			distance2 = ImageIO.read(new File("Distance-original.png"));
			parkingNo = ImageIO.read(new File("Parking-no.png"));
			parkingYes = ImageIO.read(new File("Parking-yes.png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public ViewFrame getViewFrame() {
		return this.viewFrame;
	}

	private void setViewFrame(final ViewFrame viewFrame) {
		this.viewFrame = viewFrame;
	}

	public void update(final Observable arg0, final Object arg1) {
		this.repaint();
	}

	public void setObservateur() {
		viewFrame.getModel().getObservable().addObserver(this);
		this.observerSet = true;
	}

	@Override
	protected void paintComponent(final Graphics graphics) {
		try {
			police = Font.createFont(Font.TRUETYPE_FONT, new File("POLICE.ttf")).deriveFont(50f);
			GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
			ge.registerFont(Font.createFont(Font.TRUETYPE_FONT, new File("POLICE.ttf")));
		} catch (IOException | FontFormatException e) {
			System.out.println("Font not found !");
		}

		graphics.clearRect(0, 0, this.getWidth(), this.getHeight());
		graphics.drawImage(circuit, 100, 300, 600, 450, this);
		graphics.drawImage(compteur, 525, 0, 250, 250, this);
		graphics.drawImage(trajet, 50, 50, 400, 65, this);
		graphics.drawImage(distance2, 0, 125, 500, 175, this);
		graphics.setFont(police);
		graphics.setColor(Color.black);

		graphics.drawImage(voiture, viewFrame.getModel().getX(), viewFrame.getModel().getY(), 50, 25, this);

		//TRAJET
		graphics.drawString(this.getViewFrame().getModel().getDebut(), 65, 40);
		graphics.drawString(this.getViewFrame().getModel().getFin(), 400, 40);
		graphics.drawString(this.getViewFrame().getModel().getActuel(), 235, 40);

//PARKING
		if (this.getViewFrame().getModel().getPossible())
			graphics.drawImage(parkingYes, 5, 775, 100, 87, this);
		else if (!this.getViewFrame().getModel().getPossible())
			graphics.drawImage(parkingNo, 5, 775, 100, 87, this);

		//DISTANCE
		if (this.getViewFrame().getModel().getDistance() > 10)
			graphics.drawString(String.valueOf(this.getViewFrame().getModel().getDistance()), 225, 225);
		else if (this.getViewFrame().getModel().getDistance() < 10)
			graphics.drawString("0" + String.valueOf(this.getViewFrame().getModel().getDistance()), 225, 225);

		//VITESSE
		if ((int) this.getViewFrame().getModel().getSpeed() > 10)
			graphics.drawString(String.valueOf((int) this.getViewFrame().getModel().getSpeed()), 625, 215);
		else if ((int) this.getViewFrame().getModel().getSpeed() < 10)
			graphics.drawString("" + (Math.round(this.getViewFrame().getModel().getSpeed() * 100)), 625, 215);

		//UNITE
		graphics.drawString("cm/s", 610, 290);
		graphics.drawString("cm", 225, 270);

		//INFORMATION
		graphics.drawString("----------------------------------------", 0, 775);
		graphics.drawString("Place dispo : " + this.getViewFrame().getModel().getParkingDispo(), 110, 830);
		repaint();
	}
}
