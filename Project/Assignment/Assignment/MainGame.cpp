
#pragma comment(lib,"glfw.lib")

#include "MainGame.h"
#include "Singletons.h"
#include "Graphics/ViewOpenGL.h"
#include "GameObjects/Player.h"


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
	m_mouseSensitivity(0.25f),
	m_running(false),
	m_player(new Player())
{
	Init();
}

//--------------------------------------------------------------------------------------

MainGame::~MainGame()
{
	delete m_player;
	m_player = nullptr;
}

//--------------------------------------------------------------------------------------

void MainGame::Init()
{
	//Camera();
	m_winWidth = 800;
	m_winHeight = 600;
	m_oldX=m_winWidth/2;
	m_oldY=m_winHeight/2;
		
	graphics->OpenWindow(m_winWidth, m_winHeight);
	graphics->SetWindowPosition(500, 100);
	graphics->SetWindowTitle("ICT311 Assignemnt");
	graphics->Init();
	gameWorld->LoadWorldTexture();

	//m_menu = texManager->loadTexture("Textures/menu.bmp");
	//if(!m_menu)
	//	std::cout << "Error Loading menu texture" << std::endl;
	
	audio->SetVolume(0.1f);
	//audio->Play2D("sounds/MF-W-90.XM", true);

	//m_camera.MoveToNow(gameWorld->GetWorldSize()/2,
	//	gameWorld->GetWorldXZHeight
	//		(gameWorld->GetWorldSize()/2, gameWorld->GetWorldSize()-20)+m_playerHeight,
	//	gameWorld->GetWorldSize()-20);

	//m_camera.yaw=0.0f;
	//m_camera.pitch=-75.0f;

	//m_player = new Player();
	m_player->SetPos(gameWorld->GetWorldSize()/2,
		gameWorld->GetWorldXZHeight
			(gameWorld->GetWorldSize()/2, gameWorld->GetWorldSize()-20),
		gameWorld->GetWorldSize()-20);
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

		//case 'n':
		//case 'N': 
		//	if(input->keyPress && !m_inputOneShot) {
		//		m_inputOneShot = true;
		//		gameWorld->TextureMapNormal();
		//	} 
		//	else if(input->keyRelease) {
		//		m_inputOneShot = false;
		//	}
		//	break;

		//case 'p':
		//case 'P': 
		//	if(input->keyPress && !m_inputOneShot) {
		//		m_inputOneShot = true;
		//		gameWorld->TextureMapProcedural();
		//	} 
		//	else if(input->keyRelease) {
		//		m_inputOneShot = false;
		//	}
		//	break;

		//case 'f':
		//case 'F': 
		//	if(input->keyPress && !m_inputOneShot) {
		//		gameWorld->GenFaultFormTerrain();
		//		m_inputOneShot = true;
		//	} 
		//	else if(input->keyRelease) {
		//		m_inputOneShot = false;
		//	}
		//	break;

		//case 'h':
		//case 'H': 
		//	if(input->keyPress && !m_inputOneShot) {
		//		gameWorld->LoadHeightMapTerrain();;
		//		m_inputOneShot = true;
		//	} 
		//	else if(input->keyRelease) {
		//		m_inputOneShot = false;
		//	}
		//	break;

		case 'l':
		case 'L': 
			if(input->keyPress && !m_inputOneShot) //{
				gameWorld->Left();
			//	m_inputOneShot = true;
			//} 
			//else if(input->keyRelease) {
			//	m_inputOneShot = false;
			//}
			break;

		case 'r':
		case 'R': 
			if(input->keyPress && !m_inputOneShot) //{
				gameWorld->Right();
			//	m_inputOneShot = true;
			//} 
			//else if(input->keyRelease) {
			//	m_inputOneShot = false;
			//}
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
				//m_camera.velocity+=Vector3D(-0.1f,0.0f,0.0f);
				m_player->UpdateVelocity(-0.1f,0.0f,0.0f);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				//m_camera.velocity=Vector3D(0.0f,0.0f,0.0f);
				m_player->SetVelocity(0.0f, 0.0f, 0.0f);
				audio->Stop("sounds/walking.wav");
			}
			break;
		      
		case 'd' :
		case 'D' :
			if(input->keyPress)	{
				//m_camera.velocity+=Vector3D(0.1f,0.0f,0.0f);
				m_player->UpdateVelocity(0.1f,0.0f,0.0f);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				//m_camera.velocity=Vector3D(0.0f,0.0f,0.0f);
				m_player->SetVelocity(0.0f, 0.0f, 0.0f);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case 'w' :
		case 'W' :
			if(input->keyPress) {
				//m_camera.velocity+=Vector3D(0.0f,0.0f,0.1f);
				m_player->UpdateVelocity(0.0f,0.0f,0.1f);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				//m_camera.velocity=Vector3D(0.0f,0.0f,0.0f);
				m_player->SetVelocity(0.0f, 0.0f, 0.0f);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case 's' :
		case 'S' :
			if(input->keyPress)	{
				//m_camera.velocity+=Vector3D(0.0f,0.0f,-0.1f);
				m_player->UpdateVelocity(0.0f,0.0f,-0.1f);
				if(audio->GetIsPlaying("sounds/walking.wav") == false)
					audio->Play2D("sounds/walking.wav", false);
			}
			else {
				//m_camera.velocity=Vector3D(0.0f,0.0f,0.0f);
				m_player->SetVelocity(0.0f, 0.0f, 0.0f);
				audio->Stop("sounds/walking.wav");
			}
			break;

		case GLFW_KEY_ESC:
			m_running=false;
			break;

		default:
			//m_camera.velocity = Vector3D(0.0f, 0.0f, 0.0f);
			m_player->SetVelocity(0.0f, 0.0f, 0.0f);
			break;
	}
	//m_player->UpdateVelocity(m_camVelocity);
	//gameWorld->InWorld(m_player->GetX(), m_player->GetZ());
	gameWorld->InWorld(m_player);
	m_player->SetY(gameWorld->GetWorldXZHeight(m_player->GetX(),m_player->GetZ()));
	
	

	//m_camera.position.y=gameWorld->GetWorldXZHeight(m_camera.position.x,m_camera.position.z)+m_playerHeight;
	//gameWorld->InWorld(m_camera.position.x, m_camera.position.z);

//	std::cout << m_camera.position.x << " " << m_camera.position.y << " " << m_camera.position.z << std::endl;
	//m_camVelocity = m_camera.velocity;
	if(input->mouseLeft) {
		int deltaX;
		int deltaY;
		deltaY = m_oldY-input->mouseY;
		deltaX = m_oldX-input->mouseX;
		//m_camera.yaw -= deltaX * m_mouseSensitivity;
		m_player->UpdateYaw(deltaX * m_mouseSensitivity);
		//m_camera.pitch += deltaY * m_mouseSensitivity;
		m_player->UpdatePitch(deltaY * m_mouseSensitivity);
	}
	m_oldX = input->mouseX;
	m_oldY = input->mouseY;

	//m_player->UpdateYaw(m_camYaw);
	//m_player->UpdatePitch(m_camPitch);
	//player = nullptr;
}

//--------------------------------------------------------------------------------------

void MainGame::GameLoop()
{
	//double logicTime0, displayTime0,logicTime1, displayTime1;
	//double logicFrequency=0.05;  //frequency of logic update - every 20ms
	//float displayFrequency = 0.02; // 50 fps

	double time0,time1;
	double frequency=0.1;  //frequency of logic update - every 20ms
	//double frequency=0.03;   // lowest good for display

	m_running = true;
	//logicTime0 = displayTime0 = glfwGetTime();
	time0 = glfwGetTime();
	
	/***************** main game loop ****************************************/  

	Animate(0); // NEED TO LOOK AT REMOVING THIS !!!!!!!!!!

	do { 
		  time1=glfwGetTime();
//////////////////////////////////////////////////////////////////
		////  // NEED TO GET THIS WORKING
		 // while(((float)time1 - time0) > frequency)
		 // { 
			//ProcessInput();

			//  time0+=frequency;
			//std::cout << "Logic" << std::endl;
   //		  }
		 // if(((float)time1 - time0) > frequency)
			//  time0 = time1 - frequency;
///////////////////////////////////////////////////////////////////
		  // THIS DOESN"T WORK AS A PROPER GAME LOOP!!!!
		if(((float)time1 - time0) > frequency) {
			time0 = time1 - frequency;
			ProcessInput();
			Update();
			//Animate(time1-time0);
			//Display(logicTime1-time0);
			//std::cout << "Logic" << std::endl;
		}
		
		Animate(time1-time0);
		//Animate(time1);
		Display(time1-time0);
		//std::cout << "Display" << std::endl;


		// Check if the window was closed
		m_running = m_running && glfwGetWindowParam( GLFW_OPENED );	
	} while (m_running);

	glfwTerminate();

	/**************** end game loop  *************************************/
}

//--------------------------------------------------------------------------------------

void MainGame::Update()
{
	gameWorld->Update();
}

//--------------------------------------------------------------------------------------

void MainGame::Display(float deltaT)
{

	graphics->BeginRendering();

		m_player->Render();
		graphics->ClearColour(0.75f,0.75f,1.0f,1.0f);

		gameWorld->Render();

		if(m_showMenu) {
			graphics->Render2D(m_menu, 50.0f, (float)m_winWidth-50,
							(float)m_winHeight-50, 50.0f);
		}

	graphics->EndRendering();
}

void MainGame::Animate(float deltaT)
{
	
	m_player->Animate(deltaT);
	gameWorld->Animate(deltaT);
	//getchar();
}