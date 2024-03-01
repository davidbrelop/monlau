class Config:

    # Configurar la URI de conexión
    DB_USER = "root"
    DB_PASSWORD = ""
    DB_HOST = "localhost"
    DB_PORT = "3306"
    DB_NAME = "test"

    DATABASE_URI = f"mysql+mysqlconnector://{DB_USER}:{DB_PASSWORD}@{DB_HOST}:{DB_PORT}/{DB_NAME}"