package model;

import com.fazecast.jSerialComm.SerialPort;
import contract.IModel;

import java.util.Observable;

public final class Model extends Observable implements IModel {

	private String message;
	public ArduinoUpdate arduinoUpdate;
	private Information info;
	private boolean infoSet = false;

	public Model() {
		SerialPort sp = SerialPort.getCommPorts()[0];
		sp.openPort();
		arduinoUpdate = new ArduinoUpdate(sp,this);
		sp.addDataListener(arduinoUpdate);
		setInformation();
	}

	private void setInformation() {
		this.info = new Information();
		this.infoSet = true;
	}

	public boolean getInfoSet() {
		return this.infoSet;
	}

	public Observable getObservable() {
		return info.getObservable();
	}

	public void action(String message) {
		this.message = message;
		String[] values = this.message.split("/");
		for (int i = 0; i < 3; i++) {
			try {
				switch (i) {
					case 0:
						this.info.setDistance(values[i]);
						break;
					case 1:
						this.info.setSpeed(values[i]);
						break;
					case 2:
						this.info.setPathFinding(values[i]);
						break;
					default:
						break;
				}
			} catch (StringIndexOutOfBoundsException e) {
			System.out.println("Input was not read !");
			}
		}
		this.info.setDonneesExiste(true);
	}

	public boolean close() {
		if (this.arduinoUpdate.ClosePort())
			return true;
		else
			return false;
	}

	public boolean open() {
		if (this.arduinoUpdate.OpenPort())
			return true;
		else
			return false;
	}

	public int getDistance() {
		return this.info.getDistance();
	}

	public float getSpeed() {
		return this.info.getSpeed();
	}

	public String getDebut() {
		return this.info.getDebut();
	}

	public String getFin() {
		return this.info.getFin();
	}

	public String getActuel() {
		return this.info.getActuel();
	}

	public Boolean getPossible() {
		return this.info.getPossible();
	}

	public Parking getParking() {
		return this.info.getParking();
	}

	public int getX() {
		return this.info.getX();
	}

	public int getY() {
		return this.info.getY();
	}

	public void animation() {
		this.info.animation();
	}

	public boolean getValeurExiste() {
		return arduinoUpdate.getValeurExiste();
	}

	public String getParkingDispo() {
		return info.getParkingDispo();
	}

}
