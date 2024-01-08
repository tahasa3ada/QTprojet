CREATE TABLE pstock (
    codedrouit INTEGER,
    codefournisseur INTEGER,
    quantitestock INTEGER,
    dateajout DATE,
    PRIMARY KEY (codedrouit, codefournisseur),
    FOREIGN KEY(codedrouit) REFERENCES produit(code),
    FOREIGN KEY(codefournisseur) REFERENCES fournisseurs(codef)
);
