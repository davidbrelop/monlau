from flask import jsonify, request
from src.config import db
from src.models.student import Student

def init_api_routes(app):

    @app.route('/api/students', methods=['GET'])
    def get_students():
        """
        Obtener la lista de estudiantes.
        ---
        tags:
            - Estudiantes
        description: Obtiene la lista de todos los estudiantes.
        responses:
            200:
                description: Respuesta exitosa
                examples:
                    application/json: [{'id': 1, 'name': 'John Doe', 'age': 25, 'spec': 'Computer Science'}]
        """
        students_list = db.sessionObject.query(Student).all()
        serialized_students = [student.serialize() for student in students_list]
        return jsonify(serialized_students)

    @app.route('/api/student/<student_id>', methods=['GET'])
    def get_student_by_id(student_id):
        """
        Obtener un estudiante por su ID.
        ---
        tags:
            - Estudiantes
        description: Obtiene los detalles de un estudiante por su ID.
        parameters:
          - name: student_id
            in: path
            type: integer
            required: true
            description: ID del estudiante.
        responses:
            200:
                description: Respuesta exitosa
                examples:
                    application/json: {'id': 1, 'name': 'John Doe', 'age': 25, 'spec': 'Computer Science'}
            404:
                description: Estudiante no encontrado
                examples:
                    application/json: {'error': 'Student not found'}
        """
        student = db.sessionObject.query(Student).get(student_id)
        if student is None:
            return jsonify({'error': 'Student not found'}), 404
        else:
            return jsonify({
                'id': student.id,
                'name': student.name,
                'age': student.age,
                'spec': student.spec
            })

    @app.route('/api/student', methods=['POST'])
    def post_student():
        """
        Agregar un nuevo estudiante.
        ---
        tags:
            - Estudiantes
        description: Agrega un nuevo estudiante a la base de datos.
        parameters:
          - name: body
            in: body
            required: true
            description: Datos del estudiante a agregar.
            schema:
                type: object
                properties:
                    name:
                        type: string
                        example: John Doe
                    age:
                        type: integer
                        example: 25
                    spec:
                        type: string
                        example: Computer Science
        responses:
            201:
                description: Estudiante agregado exitosamente
                examples:
                    application/json: {'id': 1, 'name': 'John Doe', 'age': 25, 'spec': 'Computer Science'}
            400:
                description: Campos requeridos faltantes
                examples:
                    application/json: {'error': 'Missing required fields'}
        """
        student_data = request.get_json()
        if 'name' not in student_data or 'age' not in student_data or 'spec' not in student_data:
            return jsonify({'error': 'Missing required fields'}), 400
        student = Student(name=student_data['name'], age=student_data['age'], spec=student_data['spec'])
        db.sessionObject.add(student)
        db.sessionObject.commit()
        return jsonify({
            'id': student.id,
            'name': student.name,
            'age': student.age,
            'spec': student.spec
        }), 201

    @app.route('/api/student/<student_id>', methods=['PUT'])
    def put_student(student_id):
        """
        Actualizar los detalles de un estudiante existente.
        ---
        tags:
            - Estudiantes
        description: Actualiza los detalles de un estudiante existente en la base de datos.
        parameters:
          - name: student_id
            in: path
            type: integer
            required: true
            description: ID del estudiante a actualizar.
          - name: body
            in: body
            required: true
            description: Nuevos datos del estudiante.
            schema:
                type: object
                properties:
                    name:
                        type: string
                        example: John Doe
                    age:
                        type: integer
                        example: 26
                    spec:
                        type: string
                        example: Computer Science
        responses:
            200:
                description: Estudiante actualizado exitosamente
                examples:
                    application/json: {'id': 1, 'name': 'John Doe', 'age': 26, 'spec': 'Computer Science'}
            404:
                description: Estudiante no encontrado
                examples:
                    application/json: {'error': 'Student not found'}
        """
        student_json = request.get_json()
        student_db = db.sessionObject.query(Student).get(student_id)
        if student_db is None:
            return jsonify({'error': 'Student not found'}), 404
        else:
            student_db.name = student_json.get("name", student_db.name)
            student_db.age = student_json.get("age", student_db.age)
            student_db.spec = student_json.get("spec", student_db.spec)
            db.sessionObject.commit()
            return jsonify({
                'id': student_db.id,
                'name': student_db.name,
                'age': student_db.age,
                'spec': student_db.spec
            })

    @app.route('/api/student/<student_id>', methods=['DELETE'])
    def delete_student(student_id):
        """
        Eliminar un estudiante.
        ---
        tags:
            - Estudiantes
        description: Elimina un estudiante de la base de datos.
        parameters:
          - name: student_id
            in: path
            type: integer
            required: true
            description: ID del estudiante a eliminar.
        responses:
            204:
                description: Estudiante eliminado exitosamente
            404:
                description: Estudiante no encontrado
                examples:
                    application/json: {'error': 'Student not found'}
        """
        student = db.sessionObject.query(Student).get(student_id)
        if student is None:
            return 'Student not found', 404
        else:
            db.sessionObject.delete(student)
            db.sessionObject.commit()
            return '', 204