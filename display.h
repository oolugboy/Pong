/*
 * display.h
 *
 *  Created on: Aug 29, 2016
 *      Author: olujimi
 */
/*
 * display.h
 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */

#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include "Shader.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <GL/glew.h>
#include "mesh.h"
#include "Transform.h"

using namespace std;




class Display
{
    public:
        Display(int height, int width, const string& title);
        virtual ~Display();
        void update();
        void update(Shader shader);
        bool getClosed();
        void updatePosition(Shader & shader, GameObject & leftP,
        		GameObject & rightP, GameObject & ball);
        void clear(float r, float g, float b, float a);
        int doesCollide();
        void handleCollision(int type);

    protected:
    private:
       // Display(const Display& other){}
      //  Display& operator=(const Display& other){}

        /** This is the pointer to the window that we are about to create **/
        SDL_Window * currWind;
        /** SDL openGL context **/
        SDL_GLContext currContext;
        bool isClosed;

};

#endif // DISPLAY_H




