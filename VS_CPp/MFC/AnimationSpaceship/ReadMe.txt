Програма виведення на екран анімації руху ракети
Застосовані підпрограми:

	afx_msg void CorpusSpaceShip(int X1,int Y1,int X2,int Y2,int DX,int DY);
	// Корпус ракети
	CorpusSpaceShip(x1, y1, x2, y2, dx, dy);

	afx_msg void ElluminateSpaceShip(int X1, int Y1, int DX, int DY);
	// Віконці
	ElluminateSpaceShip(x1, y1, dx, dy);

	afx_msg void EquipmentSpaceShip(int X1, int Y1, int X2, int Y2, int DX, int DY);
        // Крыла ракети
	EquipmentSpaceShip(x1, y1, x2, y2, dx, dy);
