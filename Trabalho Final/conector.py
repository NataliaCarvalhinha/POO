import mysql.connector
from conexao import conectarMysql, desconectarMysql

def buscarProduto(codigo_produto):
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT Produto.*, ProdutoDesconto.desconto FROM Produto LEFT JOIN ProdutoDesconto ON ProdutoDesconto.codigo = Produto.codigo WHERE Produto.codigo = %s", (codigo_produto,))
        result = cursor.fetchone()
        desconectarMysql(cursor, conn)
        return result
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def buscarProdutoNome(nome_produto):
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT Produto.*, ProdutoDesconto.desconto FROM Produto LEFT JOIN ProdutoDesconto ON ProdutoDesconto.codigo = Produto.codigo WHERE Produto.nome = %s", (nome_produto,))
        result = cursor.fetchone()
        desconectarMysql(cursor, conn)
        return result
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def inserirProduto(nome_produto, quantidade_produto, valor_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "INSERT INTO Produto (nome, quantidade, valor) VALUES (%s, %s, %s)"
        val = (nome_produto, quantidade_produto, valor_produto)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def inserirDesconto(codigo_produto, desconto_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "INSERT INTO ProdutoDesconto (codigo, desconto) VALUES (%s, %s)"
        val = (codigo_produto, desconto_produto)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def atualizarProduto(codigo_produto, novo_nome_produto, nova_quantidade_produto, novo_valor_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "UPDATE Produto SET nome = %s, quantidade = %s, valor = %s WHERE codigo = %s"
        val = (novo_nome_produto, nova_quantidade_produto, novo_valor_produto, codigo_produto)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def atualizarDesconto(codigo_produto, novo_desconto):
    try:
        conn, cursor = conectarMysql()
        sql = "UPDATE ProdutoDesconto SET desconto = %s WHERE codigo = %s"
        val = (novo_desconto, codigo_produto)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def deletarProduto(codigo_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "DELETE FROM Produto WHERE codigo = %s"
        val = (codigo_produto,)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def deletarDesconto(codigo_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "DELETE FROM ProdutoDesconto WHERE codigo = %s"
        val = (codigo_produto,)
        cursor.execute(sql, val)
        conn.commit()
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def listarProdutos():
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT Produto.*, ProdutoDesconto.desconto FROM Produto LEFT JOIN ProdutoDesconto ON ProdutoDesconto.codigo = Produto.codigo")
        result = cursor.fetchall()
        desconectarMysql(cursor, conn)
        return result
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")



