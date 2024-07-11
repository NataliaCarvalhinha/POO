from dotenv import load_dotenv
import os
import mysql.connector

def conectarMysql():
    load_dotenv()
    conn = mysql.connector.connect(
        host=os.getenv("MYSQL_HOST"),
        port=os.getenv("MYSQL_PORT"),
        database=os.getenv("MYSQL_DATABASE"),
        user=os.getenv("MYSQL_USER"),
        password=os.getenv("MYSQL_PASSWORD"),
        auth_plugin='mysql_native_password'
    )
    return conn, conn.cursor()

def desconectarMysql(cursor, conn):
    cursor.close()
    conn.close()

