from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, declarative_base
from src.config.config import Config

# Crear el motor de la base de datos
engine = create_engine(Config.DATABASE_URI)

# Crear una instancia de la sesión
Session = sessionmaker(bind=engine)
sessionObject = Session()

# Definir un modelo de tabla utilizando SQLAlchemy
Base = declarative_base()