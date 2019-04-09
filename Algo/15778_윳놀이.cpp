#pragma warning(disable : 4996)

#include <iostream>
using namespace std;

struct pos {
	int x, y, team;
};

pos user[8];
char piece, yut[5];
const int dx[] = { 0, 0, 1, 1 }, dy[] = { 0, 1, 0, 1 };
const char c[] = { 'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd' };
char a[32][33] = {
"..----..----..----..----..----..", // (0,0)  (0,6)  (0,12)  (0,18)  (0,24)  (0,30)
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |", //        (5,5)               (5,25)
"..   ..                  ..   ..", // (6,0)                                 (6,30)
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |" ,
"|         ..        ..         |", //             (10,10)    (10,20)
"|         ..        ..         |",
"..          \\      /          ..",// (12,0)                                (12,30)
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |", //                  (15,15)
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",// (18,0)                                (18,30)
"..          /      \\          ..",
"|         ..        ..         |", //             (20,10)    (20,20)
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",// (24,0)                                (24,30)
"..   ..                  ..   ..", //        (25,5)              (25,25)
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..", // (30,0) (30,6) (30,12) (30,18) (30,24) (30,30)
"..----..----..----..----..----.." };

void print() {
	// Place pieces on board.
	for (int i = 0; i < 8; i++) {
		int &x = user[i].x, &y = user[i].y;
		if (x != -1) {
			a[x][y] = c[i];
		}
	}
	// Print yut-nori board.
	for (int i = 0; i < 32; i++) cout << a[i] << '\n';
	cout << '\n';
}

void init() {
	// Initialize pieces.
	for (int i = 0; i < 8; i++) {
		user[i].x = -1;
		user[i].y = -1;
		user[i].team = 0;
	}
}

bool create() {
	int u = (piece - 'A') % 28;
	int &x = user[u].x, &y = user[u].y;
	// Create new user.
	if (x == -1) {
		x = 30 + dx[u % 4];
		y = 30 + dy[u % 4];
		return true;
	}
	else return false;
}

int action() {
	// Count yut number.
	int move = 0;
	for (int i = 0; i < 4; i++) {
		if (yut[i] == 'F') move++;
	}
	return move ? move : 5;
}

void outside(int *x, int *move, int limit, int d) {
	// Move along the outside edge line.
	while (*x != limit && *move) {
		(*x) += d;
		(*move)--;
	}
}

void inside(int *x, int *y, int *move, int limit, int d1, int d2) {
	// Move along the inside diagonal line.
	while (*x != limit && *move) {
		(*x) += d1;
		(*y) += d2;
		(*move)--;
	}
}

void finish(int *x, int *y, int *team, int *move, int u) {
	// User finishes the game.
	*x = -1;
	*y = -1;
	*move = 0;
	// Teammates finish the game.
	int k = u < 4 ? 0 : 4;
	for (int i = k; i < k + 4; i++) {
		if ((*team) & (1 << i)) {
			user[i].x = -1;
			user[i].y = -1;
			user[i].team = 0;
		}
	}
	*team = 0;
}

void ally() {
	// Find out if the user has teammates.
	int u = (piece - 'A') % 28;
	int x = user[u].x - dx[u % 4], y = user[u].y - dy[u % 4];
	int k = u < 4 ? 0 : 4;
	for (int i = k; i < k + 4; i++) {
		if (u == i) continue;
		if (user[u].team & (1 << i)) continue;
		if (user[i].x != -1) {
			for (int j = 0; j < 4; j++) {
				// Add teammates on the user.
				if (user[i].x == x + dx[j] && user[i].y == y + dy[j]) {
					user[u].team |= (1 << i);
				}
			}
		}
	}
}

void together(int x, int y, int u, int team) {
	// Move together with teammates.
	int k = u < 4 ? 0 : 4;
	for (int i = k; i < k + 4; i++) {
		if (team & (1 << i)) {
			user[i].x = x + dx[i % 4];
			user[i].y = y + dy[i % 4];
			user[i].team |= (1 << u);
		}
	}
}

void enemy() {
	// Find out if there are enemies in user's position.
	int u = (piece - 'A') % 28;
	int x = user[u].x, y = user[u].y;
	int k = u < 4 ? 4 : 0;
	for (int i = k; i < k + 4; i++) {
		if (user[i].x != -1) {
			for (int j = 0; j < 4; j++) {
				if (user[i].x == x + dx[j] && user[i].y == y + dy[j]) {
					// The enemies go back to the starting point.
					user[i].x = -1;
					user[i].y = -1;
					user[i].team = 0;
				}
			}
		}
	}
}

void solve() {
	int u = (piece - 'A') % 28;
	int &x = user[u].x, &y = user[u].y, &team = user[u].team;
	int move = action();
	bool finished = false;
	ally();
	if (create()) {
		// First start.
		x -= 6;
		move--;
	}
	x -= dx[u % 4], y -= dy[u % 4];
	// Move pieces.
	if (x == 0 && y == 30) {
		inside(&x, &y, &move, 30, 5, -5); // ↙
	}
	else if (x == 0 && y == 0) {
		inside(&x, &y, &move, 30, 5, 5);  // ↘
	}
	else if (x == 15 && y == 15) {
		inside(&x, &y, &move, 30, 5, 5);  // ↘
		if (move) finish(&x, &y, &team, &move, u), finished = true;
	}
	else if (x == 30 && y == 30) {
		if (move) finish(&x, &y, &team, &move, u), finished = true;
	}
	else if (x % 6 == 0 || y % 6 == 0) {
		while (move) {
			if (y == 30) outside(&x, &move, 0, -6); // ↑
			if (x == 0) outside(&y, &move, 0, -6);  // ←
			if (y == 0) outside(&x, &move, 30, 6);  // ↓
			if (x == 30) {
				outside(&y, &move, 30, 6);          // →
				if (move) finish(&x, &y, &team, &move, u), finished = true;
			}
		}
	}
	else {
		if (x == y) {
			inside(&x, &y, &move, 30, 5, 5);  // ↘
			if (move) finish(&x, &y, &team, &move, u), finished = true;
		}
		else {
			inside(&x, &y, &move, 30, 5, -5); // ↙
			if (move) outside(&y, &move, 30, 6);
		}
	}
	if (!finished) {
		if (team) together(x, y, u, team);
		enemy();
		x += dx[u % 4], y += dy[u % 4];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	init();
	while (n--) {
		cin >> piece >> yut;
		solve();
	}
	print();
	return 0;
}


/*
#include <iostream>

using namespace std;

char map[32][33] = {
"..----..----..----..----..----..", // (0,0)  (0,6)  (0,12)  (0,18)  (0,24)  (0,30)
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |", //        (5,5)               (5,25)
"..   ..                  ..   ..", // (6,0)                                 (6,30)
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |" ,
"|         ..        ..         |", //             (10,10)    (10,20)
"|         ..        ..         |",
"..          \\      /          ..",// (12,0)                                (12,30)
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |", //                  (15,15)
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",// (18,0)                                (18,30)
"..          /      \\          ..",
"|         ..        ..         |", //             (20,10)    (20,20)
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",// (24,0)                                (24,30)
"..   ..                  ..   ..", //        (25,5)              (25,25)
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..", // (30,0) (30,6) (30,12) (30,18) (30,24) (30,30)
"..----..----..----..----..----.." };

struct P {
	int x;
	int y;
	int team;
};

P user[8];

char piece;
char yut[5];

int dx[4] = { 0, 0, 1, 1 };
int dy[4] = { 0, 1, 0, 1 };

char c[8] = { 'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd' };

// 최종 맵 출력
void print_map()
{

	for (int i = 0; i < 8; i++) {
		int &x = user[i].x, &y = user[i].y;
		if (x != -1) {
			map[x][y] = c[i];
		}
	}
	for (int i = 0; i < 32; i++) cout << map[i] << '\n';
	cout << '\n';
}


// 말 잡혔을 때, 사용자 초기화 함수
void init() {
	for (int i = 0; i < 8; i++) {
		user[i].x = -1;
		user[i].y = -1;
		user[i].team = 0;
	}
}


// 새로운 말판 생성
bool create() {
	int u = (piece - 'A') % 28;
	int &x = user[u].x, &y = user[u].y;
	if (x == -1) {
		x = 30 + dx[u % 4];
		y = 30 + dy[u % 4];
		return true;
	}
	else return false;
}

// 같은 위치 팀원 찾기
void find_team() {

	int u = (piece - 'A') % 28;

	int x = user[u].x - dx[u % 4];
	int y = user[u].y - dy[u % 4];

	// 대문자면 k = 0 , 소문자면 k = 4
	int k = u < 4 ? 0 : 4;

	for (int i = k; i < k + 4; i++) {
		if (u == i) continue;
		if (user[u].team & (1 << i)) continue;
		if (user[i].x != -1) {
			for (int j = 0; j < 4; j++) {
				if (user[i].x == x + dx[j] && user[i].y == y + dy[j]) {
					user[u].team |= (1 << i);
				}
			}
		}
	}
}

// 팀원 엎기
void together(int x, int y, int u, int team) {
	// Move together with teammates.
	int k = u < 4 ? 0 : 4;
	for (int i = k; i < k + 4; i++) {
		if (team & (1 << i)) {
			user[i].x = x + dx[i % 4];
			user[i].y = y + dy[i % 4];
			user[i].team |= (1 << u);
		}
	}
}

// 적 사냥
void enemy() {
	// Find out if there are enemies in user's position.
	int u = (piece - 'A') % 28;
	int x = user[u].x, y = user[u].y;
	int k = u < 4 ? 4 : 0;
	for (int i = k; i < k + 4; i++) {
		if (user[i].x != -1) {
			for (int j = 0; j < 4; j++) {
				if (user[i].x == x + dx[j] && user[i].y == y + dy[j]) {
					// The enemies go back to the starting point.
					user[i].x = -1;
					user[i].y = -1;
					user[i].team = 0;
				}
			}
		}
	}
}


// 말판 이동 횟수 찾기
int count_F()
{
	int move = 0;
	for (int i = 0; i < 4; i++)
		if (yut[i] == 'F')
			move++;
	
	return move != 0 ? move : 5;
}

void outside(int *x, int *move, int limit, int d) {
	// Move along the outside edge line.
	while (*x != limit && *move) {
		(*x) += d;
		(*move)--;
	}
}

void inside(int *x, int *y, int *move, int limit, int d1, int d2) {
	// Move along the inside diagonal line.
	while (*x != limit && *move) {
		(*x) += d1;
		(*y) += d2;
		(*move)--;
	}
}

void finish(int *x, int *y, int *team, int *move, int u) {
	// User finishes the game.
	*x = -1;
	*y = -1;
	*move = 0;
	// Teammates finish the game.
	int k = u < 4 ? 0 : 4;
	for (int i = k; i < k + 4; i++) {
		if ((*team) & (1 << i)) {
			user[i].x = -1;
			user[i].y = -1;
			user[i].team = 0;
		}
	}
	*team = 0;
}


void put_yut()
{
	int u = (piece - 'A') % 28;
	
	int &x = user[u].x;
	int &y = user[u].y;
	int &team = user[u].team;

	int move = count_F();

	bool finished = false;
	find_team();

	if (create()) {
		// First start.
		x -= 6;
		move--;
	}
	x -= dx[u % 4], y -= dy[u % 4];
	// Move pieces.
	if (x == 0 && y == 30) {
		inside(&x, &y, &move, 30, 5, -5); // ↙
	}
	else if (x == 0 && y == 0) {
		inside(&x, &y, &move, 30, 5, 5);  // ↘
	}
	else if (x == 15 && y == 15) {
		inside(&x, &y, &move, 30, 5, 5);  // ↘
		if (move) finish(&x, &y, &team, &move, u), finished = true;
	}
	else if (x == 30 && y == 30) {
		if (move) finish(&x, &y, &team, &move, u), finished = true;
	}
	else if (x % 6 == 0 || y % 6 == 0) {
		while (move) {
			if (y == 30) outside(&x, &move, 0, -6); // ↑
			if (x == 0) outside(&y, &move, 0, -6);  // ←
			if (y == 0) outside(&x, &move, 30, 6);  // ↓
			if (x == 30) {
				outside(&y, &move, 30, 6);          // →
				if (move) finish(&x, &y, &team, &move, u), finished = true;
			}
		}
	}
	else {
		if (x == y) {
			inside(&x, &y, &move, 30, 5, 5);  // ↘
			if (move) finish(&x, &y, &team, &move, u), finished = true;
		}
		else {
			inside(&x, &y, &move, 30, 5, -5); // ↙
			if (move) outside(&y, &move, 30, 6);
		}
	}
	if (!finished) {
		if (team) together(x, y, u, team);
		enemy();
		x += dx[u % 4], y += dy[u % 4];
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> piece >> yut;
		put_yut();
	}

	print_map();
	return 0;
}
*/