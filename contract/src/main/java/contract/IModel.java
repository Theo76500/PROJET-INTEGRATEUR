package contract;

import java.util.Observable;

public interface IModel {

	Observable getObservable();
	int getDistance();
	float getSpeed();
	String getDebut();
	String getFin();
	String getActuel();
	Boolean getPossible();
	int getY();
	int getX();
	void animation();
	void action(String message);
	boolean getInfoSet();
	String getParkingDispo();
}
