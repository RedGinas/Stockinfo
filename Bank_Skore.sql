CREATE TABLE Skore(
  ID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  Name_user VARCHAR(30),
  Money FLOAT,
  Status SET("active","blocked") DEFAULT "blocked"
);
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 123, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 5712, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 25511, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 711, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', -9811, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 905, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 2468, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', -2711, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', 854, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Bob', -1281, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Frank', 15911, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Frank', 172, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Frank', 519, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 9456720, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 72982000, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 821921980, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 101000000, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 19550000, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 15692000, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 898121020, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 65392000, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 17555900, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', 85123000, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Gabe', -9123000, 'blocked');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Frank', -519, 'active');
INSERT INTO Bank.Skore (Name_user, Money, Status) VALUES ('Pad', 270, 'active');