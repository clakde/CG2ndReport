#include <GL/glut.h>

float angleX = 0.0f; // X�� ȸ�� ����
float angleY = 0.0f; // Y�� ȸ�� ����
float translateX = 0.0f; // X�� �̵�
float translateY = 0.0f; // Y�� �̵�
float scale = 1.0f; // ũ�� ����
float cameraX = 0.0f; // ī�޶� X ��ġ
float cameraY = 0.0f; // ī�޶� Y ��ġ
float cameraZ = 5.0f; // ī�޶� Z ��ġ

void drawCube() {
    glBegin(GL_QUADS);

    // ť�� �ո� �׸���
    glColor3f(1.0f, 0.0f, 0.0f); // �ո� ���������� ����
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // ť�� �޸� �׸���
    glColor3f(0.0f, 1.0f, 0.0f); // �޸��� �ʷϻ�
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // ť�� ���ʸ�
    glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // �����ʸ�
    glColor3f(1.0f, 1.0f, 0.0f); // �����
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // ���ʸ�
    glColor3f(1.0f, 0.0f, 1.0f); // �����
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // �Ʒ��ʸ�
    glColor3f(0.0f, 1.0f, 1.0f); // �ϴû�
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ī�޶� ��ġ ����
    gluLookAt(cameraX, cameraY, cameraZ,  // ī�޶� ��ġ
        0.0f, 0.0f, 0.0f,  // �ٶ󺸴� ��
        0.0f, 1.0f, 0.0f); // �� ����

    // �� ��ȯ
    glTranslatef(translateX, translateY, 0.0f); // �̵�
    glScalef(scale, scale, scale); // ũ�� ����
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // X�� ȸ��
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Y�� ȸ��
    drawCube();

    glutSwapBuffers();
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP: // �� ����Ű
        angleX -= 5.0f; // X����� ���� ȸ��
        break;
    case GLUT_KEY_DOWN: // �Ʒ� ����Ű
        angleX += 5.0f; // X�� ȸ��
        break;
    case GLUT_KEY_LEFT: // ���� ����Ű
        angleY -= 5.0f; // Y�� ȸ��
        break;
    case GLUT_KEY_RIGHT: // ������ ����Ű
        angleY += 5.0f; // Y�� ȸ��
        break;
    default:
        break; // �ٸ� ����Ű�� ���� �⺻ ó��
    }
    glutPostRedisplay();
}

void handleNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': // ���� �̵�
        translateY += 0.1f;
        break;
    case 's': // �Ʒ��� �̵�
        translateY -= 0.1f;
        break;
    case 'a': // �������� �̵�
        translateX -= 0.1f;
        break;
    case 'd': // ���������� �̵�
        translateX += 0.1f;
        break;
    case 'q': // ũ�� ����
        scale += 0.1f;
        break;
    case 'e': // ũ�� ����
        scale -= 0.1f;
        if (scale < 0.1f) scale = 0.1f; // �ּ� ũ�� ����
        break;
    case 'i': // ī�޶� Z�� ������ �̵�
        cameraZ -= 0.1f;
        break;
    case 'k': // ī�޶� Z�� �ڷ� �̵�
        cameraZ += 0.1f;
        break;
    case 'j': // ī�޶� X�� �������� �̵�
        cameraX -= 0.1f;
        break;
    case 'l': // ī�޶� X�� ���������� �̵�
        cameraX += 0.1f;
        break;
    case 'u': // ī�޶� Y�� ���� �̵�
        cameraY += 0.1f;
        break;
    case 'o': // ī�޶� Y�� �Ʒ��� �̵�
        cameraY -= 0.1f;
        break;
    case 27: // ESC Ű�� ����
        exit(0);
        break;
    default:
        break; // �ٸ� Ű�� ���� �⺻ ó��
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // ���� ����
    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f); // �������� ����
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D shape �� ��ȯ + ������ȯ");//��� ȭ���� ���� ����
    init(); // �ʱ�ȭ �Լ� ȣ��
    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys); // ����Ű �Է� ó�� �Լ�
    glutKeyboardFunc(handleNormalKeys); // �Ϲ� Ű �Է� ó�� �Լ�
    glutMainLoop();
    return 0;
}
