CREATE TABLE historiqueSORTIE (
    codePsortie INTEGER PRIMARY KEY AUTOINCREMENT,
    codedrouit INTEGER,
    codefournisseur INTEGER,
    nom TEXT NOT NULL,
    quantiteSORTIE INTEGER,
    prixSORTIE REAL,
    MONTANT REAL,
    FOREIGN KEY(codedrouit) REFERENCES produit(code),
    FOREIGN KEY(codefournisseur) REFERENCES fournisseurs(codef)
);