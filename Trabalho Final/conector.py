import mysql.connector
from conexao import conectarMysql, desconectarMysql

def buscarProduto(codigo_produto):
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT * FROM Produto WHERE codigo = %s", (codigo_produto,))
        result = cursor.fetchone()
        desconectarMysql(cursor, conn)
        return result
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def buscarProdutoNome(nome_produto):
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT * FROM Produto WHERE nome = %s", (nome_produto,))
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
        print(f"Produto inserido com ID: {cursor.lastrowid}")
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
        print(f"Produto com ID {codigo_produto} atualizado")
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def deletarProduto(nome_produto):
    try:
        conn, cursor = conectarMysql()
        sql = "DELETE FROM Produto WHERE nome = %s"
        val = (nome_produto,)
        cursor.execute(sql, val)
        conn.commit()
        print(f"Produto '{nome_produto}' deletado")
        desconectarMysql(cursor, conn)
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

def listarProdutos():
    try:
        conn, cursor = conectarMysql()
        cursor.execute("SELECT * FROM Produto")
        result = cursor.fetchall()
        desconectarMysql(cursor, conn)
        return result
    except mysql.connector.Error as erro:
        print(f"Erro: {erro}")

if __name__ == "__main__":
    produtos = listarProdutos()
    for produto in produtos:
        print(produto)
    print(buscarProduto(44))


