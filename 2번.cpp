#include <GL/glut.h>

float angleX = 0.0f; // X축 회전 각도
float angleY = 0.0f; // Y축 회전 각도
float translateX = 0.0f; // X축 이동
float translateY = 0.0f; // Y축 이동
float scale = 1.0f; // 크기 조절
float cameraX = 0.0f; // 카메라 X 위치
float cameraY = 0.0f; // 카메라 Y 위치
float cameraZ = 5.0f; // 카메라 Z 위치

void drawCube() {
    glBegin(GL_QUADS);

    // 큐브 앞면 그리기
    glColor3f(1.0f, 0.0f, 0.0f); // 앞면 빨간색으로 설정
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // 큐브 뒷면 그리기
    glColor3f(0.0f, 1.0f, 0.0f); // 뒷면은 초록색
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // 큐브 왼쪽면
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // 오른쪽면
    glColor3f(1.0f, 1.0f, 0.0f); // 노란색
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // 위쪽면
    glColor3f(1.0f, 0.0f, 1.0f); // 보라색
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // 아래쪽면
    glColor3f(0.0f, 1.0f, 1.0f); // 하늘색
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 카메라 위치 설정
    gluLookAt(cameraX, cameraY, cameraZ,  // 카메라 위치
        0.0f, 0.0f, 0.0f,  // 바라보는 점
        0.0f, 1.0f, 0.0f); // 위 방향

    // 모델 변환
    glTranslatef(translateX, translateY, 0.0f); // 이동
    glScalef(scale, scale, scale); // 크기 조절
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // X축 회전
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Y축 회전
    drawCube();

    glutSwapBuffers();
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP: // 위 방향키
        angleX -= 5.0f; // X축기준 위로 회전
        break;
    case GLUT_KEY_DOWN: // 아래 방향키
        angleX += 5.0f; // X축 회전
        break;
    case GLUT_KEY_LEFT: // 왼쪽 방향키
        angleY -= 5.0f; // Y축 회전
        break;
    case GLUT_KEY_RIGHT: // 오른쪽 방향키
        angleY += 5.0f; // Y축 회전
        break;
    default:
        break; // 다른 방향키에 대한 기본 처리
    }
    glutPostRedisplay();
}

void handleNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': // 위로 이동
        translateY += 0.1f;
        break;
    case 's': // 아래로 이동
        translateY -= 0.1f;
        break;
    case 'a': // 왼쪽으로 이동
        translateX -= 0.1f;
        break;
    case 'd': // 오른쪽으로 이동
        translateX += 0.1f;
        break;
    case 'q': // 크기 증가
        scale += 0.1f;
        break;
    case 'e': // 크기 감소
        scale -= 0.1f;
        if (scale < 0.1f) scale = 0.1f; // 최소 크기 제한
        break;
    case 'i': // 카메라 Z축 앞으로 이동
        cameraZ -= 0.1f;
        break;
    case 'k': // 카메라 Z축 뒤로 이동
        cameraZ += 0.1f;
        break;
    case 'j': // 카메라 X축 왼쪽으로 이동
        cameraX -= 0.1f;
        break;
    case 'l': // 카메라 X축 오른쪽으로 이동
        cameraX += 0.1f;
        break;
    case 'u': // 카메라 Y축 위로 이동
        cameraY += 0.1f;
        break;
    case 'o': // 카메라 Y축 아래로 이동
        cameraY -= 0.1f;
        break;
    case 27: // ESC 키로 종료
        exit(0);
        break;
    default:
        break; // 다른 키에 대한 기본 처리
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 배경색 설정
    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f); // 프로젝션 설정
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D shape 모델 변환 + 시점변환");//출력 화면의 제목 설정
    init(); // 초기화 함수 호출
    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys); // 방향키 입력 처리 함수
    glutKeyboardFunc(handleNormalKeys); // 일반 키 입력 처리 함수
    glutMainLoop();
    return 0;
}
