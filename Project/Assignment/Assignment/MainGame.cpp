
#pragma comment(lib,"glfw.lib")

#include "MainGame.h"
#include "Singletons.h"
#include "ViewOpenGL.h"

#include <iostream>
#include <iomanip>
#include <time.h>
#include <gl/glfw.h>

//--------------------------------------------------------------------------------------

MainGame::MainGame() :
	m_inputOneShot(false),
	m_showMenu(false),
	m_wireframe(false),
	m_menu(0),
	m_playerHeight(15.0f),
	m_mouseSensitivity(0.25f),
	m_running(false)
{
	Init();
}

//--------------------------------------------------------------------------------------

MainGame::~MainGame()
{
}

//--------------------------------------------------------------------------------------

void MainGame::Init()
{
	Camera();
	m_winWidth = 800;
	m_winHeight = 600;
	m_oldX=m_winWidth/2;
	m_oldY=m_winHeight/2;
		
	graphics->OpenWindow(m_winWidth, m_winHeight);
	graphics->SetWindowPosition(500, 100);
	graphics->SetWindowTitle("ICT311 Assignemnt");
	graphics->Init();
	gameWorld->LoadWorldTexture();

	m_menu = texManager->loadTexture("graphics/menu.bmp");
	if(!m_menu)
		std::cout << "Error Loading menu texture" << std::endl;
	
	audio->SetVolume(0.1f);
	//audio->Play2D("sounds/MF-W-90.XM", true);

	m_camera.MoveToNow(gameWorld->GetWorldSize()/2,
		gameWorld->GetWorldXZHeight
			(gameWorld->GetWorldSize()/2, gameWorld->GetWorldSize()-20)+m_playerHeight,
		gameWorld->GetWorldSize()-20);

	m_camera.yaw=0;
	m_camera.pitch=-75;
}

//--------------------------------------------------------------------------------------

void MainGame::Run()
{
	GameLoop();
}

//--------------------------------------------------------------------------------------

void MainGame::ProcessInput()
{
	switch(input->key)
	{
		case 'k':
		case 'K': 
			if(input->keyPress && !m_wireframe && !m_inputOneShot) {
				m_inputOneShot = true;
				m_wireframe = true;
				graphics->SetWireframeView();
			} 
			else if(input->keyPress && m_wireframe && !m_inputOneShot) {
				m_inputOneShot = true;
				m_wireframe = false;
				graphics->SetSolidView();
			}
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'n':
		case 'N': 
			if(input->keyPress && !m_inputOneShot) {
				m_inputOneShot = true;
				gameWorld->TextureMapNormal();
			} 
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'p':
		case 'P': 
			if(input->keyPress && !m_inputOneShot) {
				m_inputOneShot = true;
				gameWorld->TextureMapProcedural();
			} 
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'f':
		case 'F': 
			if(input->keyPress && !m_inputOneShot) {
				gameWorld->GenFaultFormTerrain();
				m_inputOneShot = true;
			} 
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'h':
		case 'H': 
			if(input->keyPress && !m_inputOneShot) {
				gameWorld->LoadHeightMapTerrain();;
				m_inputOneShot = true;
			} 
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'm':
		case 'M': 
			if(input->keyPress && !m_inputOneShot && !m_showMenu) {
				m_showMenu = true;
				m_inputOneShot = true;
			} 
			else if(input->keyPress && !m_inputOneShot && m_showMenu) {
				m_showMenu = false;
				m_inputOneShot = true;
			}
			else if(input->keyRelease) {
				m_inputOneShot = false;
			}
			break;

		case 'x':
		case 'X':
			m_running = false;
			break;

		case 'a' :
		case 'A' :
			if(input->keyPress) {
				m_camera.velocity+=Vector3D(-0.1,0,0);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				m_camera.velocity=Vector3D(0,0,0);
				audio->Stop("sounds/walking.wav");
			}
			break;
		      
		case 'd' :
		case 'D' :
			if(input->keyPress)	{
				m_camera.velocity+=Vector3D(0.1,0,0);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				m_camera.velocity=Vector3D(0,0,0);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case 'w' :
		case 'W' :
			if(input->keyPress) {
				m_camera.velocity+=Vector3D(0,0,0.1);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				m_camera.velocity=Vector3D(0,0,0);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case 's' :
		case 'S' :
			if(input->keyPress)	{
				m_camera.velocity+=Vector3D(0,0,-0.1);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				m_camera.velocity=Vector3D(0,0,0);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case GLFW_KEY_ESC:
			m_running=false;
			break;

		default:
			m_camera.velocity = Vector3D(0.0f, 0.0f, 0.0f);
			break;
	}

	m_camera.position.y=gameWorld->GetWorldXZHeight(m_camera.position.x,m_camera.position.z)+m_playerHeight;
	gameWorld->InWorld(m_camera.position.x, m_camera.position.z);

	if(input->mouseLeft) {
		int deltaX;
		int deltaY;
		deltaY = m_oldY-input->mouseY;
		deltaX = m_oldX-input->mouseX;
		m_camera.yaw -= deltaX * m_mouseSensitivity;
		m_camera.pitch += deltaY * m_mouseSensitivity;
	}
	m_oldX = input->mouseX;
	m_oldY = input->mouseY;
}

//--------------------------------------------------------------------------------------

void MainGame::GameLoop()
{
	double time0,time1;
	double frequency=0.05;  //frequency of logic update - every 20ms

	m_running = true;
	time0 = glfwGetTime();

	/***************** main game loop ****************************************/  

	do { 
		time1=glfwGetTime();
		if(((float)time1 - time0) > frequency) {
			time0 = time1 - frequency;
			ProcessInput();
			Display(time1-time0);
		}
	  
		// Check if the window was closed
		m_running = m_running && glfwGetWindowParam( GLFW_OPENED );	
	} while (m_running);

	glfwTerminate();

	/**************** end game loop  *************************************/
	}

//--------------------------------------------------------------------------------------

void MainGame::Display(float deltaT)
{
	m_camera.Animate(deltaT);

	graphics->BeginRendering();

		graphics->UpdateCamera(m_camera.position, m_camera.lookAt);
		graphics->ClearColour(0.75f,0.75f,1.0f,1.0f);

		gameWorld->Render();

		if(m_showMenu) {
			graphics->Render2D(m_menu, 50.0f, (float)m_winWidth-50,
							(float)m_winHeight-50, 50.0f);
		}

	graphics->EndRendering();
}
