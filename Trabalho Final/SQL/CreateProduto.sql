CREATE TABLE Produto (
    codigo INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    quantidade INT NOT NULL,
    valor DECIMAL(10, 2) NOT NULL
);

CREATE TABLE ProdutoDesconto (
    codigo INT PRIMARY KEY,
    FOREIGN KEY (codigo) REFERENCES Produto(codigo),
    descontoPorcentagem DECIMAL(5, 2) NOT NULL
    ON DELETE CASCADE
);
