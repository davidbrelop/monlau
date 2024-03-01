from sqlalchemy import Column, Integer, String
from src.config import db

class Student(db.Base):
    __tablename__ = "students"

    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(String(length=50), nullable=False)
    age = Column(Integer, nullable=False)
    spec = Column(String(length=50), nullable=False)

    def serialize(self):
        return {'id': self.id, 'name': self.name, 'age': self.age, 'spec': self.spec}

    def __init__(self, name, age, spec):
        self.name = name
        self.age = age
        self.spec = spec

    def __str__(self):
        return f"ID = {self.id}, Name = {self.name}, Age = {self.age}, Spec = {self.spec})"