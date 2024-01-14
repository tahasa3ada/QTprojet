CREATE TABLE produit (
    code INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT NOT NULL ,
    description TEXT,
    prix REAL,
    quantite_entree_stock INTEGER,
    idfourni INTEGER,
    FOREIGN KEY(idfourni) REFERENCES fournisseurs(codef)
);

