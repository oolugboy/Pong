/*
 * Transform.h
 *
 *  Created on: Sep 3, 2016
 *      Author: olujimi
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
	public:
		Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(1,0,0),
				const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
	 	{
			this->pos = pos;
			this->rot = rot;
			this->scale = scale;
			this->rotAngle = 0;
	 	}

		glm::mat4 getModel() const
		{
			glm::mat4 posMatrix = glm::translate(pos);
			glm::mat4 rotMatrix = glm::rotate(rotAngle,rot);
			glm::mat4 scaleMatrix = glm::scale(scale);

			return posMatrix * rotMatrix * scaleMatrix;
		}

		void setPos(const glm::vec3& pos){this->pos = pos;}
		void setRot(const glm::vec3& rot){this->rot = rot;}
		void setScale(const glm::vec3& scale){this->scale = scale;}

		glm::vec3 & getPos(){ return pos; }
		glm::vec3 & getRot(){ return rot; }
		glm::vec3 & getScale(){ return scale; }
		float & getRotAngle(){ return rotAngle; }

		//virtual ~Transform();
	protected:
	private :
		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 scale;
		float rotAngle;
};

#endif /* TRANSFORM_H_ */



