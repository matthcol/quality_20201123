"""
database.py : config orm
"""

from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker


SQLALCHEMY_DATABASE_URL = "postgresql://movie:password@localhost/dbmovie"
SQLALCHEMY_DATABASE_URL = "mysql+pymysql://movie:password@localhost/dbmovie"
SQLALCHEMY_DATABASE_URL = "sqlite:///./sql_app.db"

engine = create_engine(
#    SQLALCHEMY_DATABASE_URL
#    SQLALCHEMY_DATABASE_URL, echo=True  # view SQL in logs
    SQLALCHEMY_DATABASE_URL, connect_args={"check_same_thread": False}
)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

Base = declarative_base()
  