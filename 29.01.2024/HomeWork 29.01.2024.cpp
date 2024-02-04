#include <iostream>
#include <string>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)
#define countNames 5
#define countGroups 7
//#define TEST

const string names[] = { "Oleg", "Pasha","Kolya","Vika", "Olya" };

class Student {
	static int id;
	int uniqId;
	string name;
	int* marks = nullptr;
	int countMarks = 0;
public:
	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = ++id;
#ifdef TEST
	cout << this << " ID:\t" << uniqId << " is created" << endl;
#endif
	}
	Student (Student& st) /* : Student()*/ {
		name = st.name;
		uniqId = st.uniqId;
		countMarks = st.countMarks;
		if (st.countMarks == 0) return;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}
	~Student() {
#ifdef TEST
		cout<< this << " ID:\t" << uniqId<< " was deleted" << endl;
#endif
 		if (marks != nullptr) {
			delete[] marks;
		}
	}
	int getUniqId() {
		return uniqId;
	}
	void operator = (Student& st) {
		name = st.name;
		uniqId = st.uniqId;
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}
	void addMark(int mark) {
		int* buf = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++) {
			buf[i] = marks[i];
		}
		buf[countMarks++] = mark;
		delete[]marks;
		marks = buf;
	}
	void delMark(int index, int mark) {
		if (countMarks == 0) return;
		if (countMarks == 1) {
			countMarks = 0;
			delete[]marks;
			marks = nullptr;
			return;
		}
		int* buf = new int[countMarks-1];
		for (int i = 0; i < index; i++) {
			buf[i] = marks[i];
		}
		for (int i = index+1; i < countMarks; i++) {
			buf[i-1] = marks[i];
		}
		delete[]marks;
		marks = buf;
		countMarks--;
	}
	void changeMark(int index, int mark) {
		if(index>=0 &&index<countMarks){
			marks[index] = mark;
		}
	}
	void showInfo() {
		cout << uniqId << ":\t" << name<<" : ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
	}

};
int Student::id = 0;

struct GroupName {
	static int num;
	static char alpha;
public:
	static string getUniqGroupName() {
		if (num == 3) return "";
		int numPrev = num;
		char alphaPrev = alpha;
		
		if (alpha == 'E') {
			alpha = 'A';
			num += 1;
		}
		else alpha++;
		
		return to_string(numPrev) + alphaPrev;
	}
};
int GroupName::num=1;
char GroupName::alpha='A';

class Group {
	string uniqId = "";
	Student** students = nullptr;
	int countStudents = 0;
public:

	Group() {
		this->countStudents = 0;
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "Group limit reached";
	}

	Group(Group& gr) {
		uniqId = gr.uniqId;
		countStudents = gr.countStudents;
		if (gr.countStudents == 0) return;
		students = new Student* [countStudents];
		for (int i = 0; i < countStudents; i++) {
			students[i] = gr.students[i];
		}
	}

	int getCountStudents() {
		return countStudents;
	}

	Student** getStudents() {
		return students;
	}

	void showInfo() {
		if (uniqId!="") cout << uniqId<<" "<<endl;
		for (int i = 0; i < countStudents; i++) {
			students[i]->showInfo();
		}
	}

	void addStudent(Student& st) {
		if (this->countStudents > 5) {
			cout << "The permissible limit of the number of students has been exceeded";
			return;
		}
		Student** buf = new Student*[countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		delete[]students;

		buf[countStudents] = new Student(st);
		
		countStudents++;
		students = buf;
	}

	void delStudent(int index) {
		if (this->countStudents == 0) {
			return;
		}
		if (this->countStudents == 1) {
			delete[] students[0];
			students = nullptr;
			countStudents--;
			return;
		}
		Student** buf = new Student * [countStudents - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = students[i];
		}
		for (int i = index+1; i < countStudents; i++) {
			buf[i-1] = students[i];
		}
	
		delete[] students[index];
		delete[] students;

		countStudents--;
		students = buf;
	}

	Student* getStudentByIndex(int index) {
		return students[index];
	}
};

class School {
	int countStudentsInSch = 0;
	int countGroupsInSch = 0;
	Student** students = nullptr;
	Group** groups = nullptr;

public:

	void moveStudentByIdToGroupByIndex(int idSt, int indexGr) {
		if (groups[indexGr]->getCountStudents() <= 5) {
			for (int k = 0; k < countGroupsInSch; k++) {
				for (int n = 0; n < groups[k]->getCountStudents(); n++) {
					if (groups[k]->getStudentByIndex(n)->getUniqId() == idSt) {
						 
						groups[indexGr]->addStudent(*(groups[k]->getStudentByIndex(n)));
						groups[k]->delStudent(n);
						cout << "Student transfer was successful" << endl;
						return;
					}
				}
			}
		}
		else cout << "The permissible limit of the number of students has been exceeded" << endl;
	}

	void delGroupByIndex(int index) {
		if (countGroupsInSch == 0) {
			return;
		}
		if (this->countGroupsInSch == 1) {
			delete[] groups[0];
			groups = nullptr;
			return;
		}
		Group** buf = new Group * [countGroupsInSch - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = groups[i];
		}
		for (int i = index + 1; i < countGroupsInSch; i++) {
			buf[i - 1] = groups[i];
		}

		delete groups[index];
		delete[]groups;

		countGroupsInSch--;
		groups = buf;
	}

	void addStudent(Student& st) {
		Student** buf = new Student* [countStudentsInSch + 1];
		for (int i = 0; i < countStudentsInSch; i++) {
			buf[i] = students[i];
		}
		delete[]students;

		buf[countStudentsInSch] = new Student(st);

		countStudentsInSch++;
		students = buf;
	}

	void addGroup(Group& gr) {
		if (countGroupsInSch == countGroups) {
			cout << "The permissible limit of the number of groups has been exceeded";
			return;
		}
		Group** buf = new Group * [countGroupsInSch + 1];
		for (int i = 0; i < countGroupsInSch; i++) {
			buf[i] = groups[i];
		}
		delete[]groups;

		buf[countGroupsInSch] = new Group(gr);

		countGroupsInSch++;
		groups = buf;
	}

	void distAllStudIntoGroups() {
		if (countStudentsInSch == 0) { 
			cout << "There are no students at school";
			return;
		}
		for (int i = 0; i < countStudentsInSch; i++) {
			int indexOfGroup = random(0, countGroupsInSch - 1);
			while (groups[indexOfGroup]->getCountStudents() <= 5) {
				groups[indexOfGroup]->addStudent(*students[i]);
				for (int j = 0; j < 4; j++) {
					int indLastStudInGr = groups[indexOfGroup]->getCountStudents() - 1;
					groups[indexOfGroup]->getStudentByIndex(indLastStudInGr)->addMark(random(2, 5));
				}
				break;
			}
		}
	}

	void showInfo() {
		for (int i = 0; i < countGroupsInSch; i++) {
			groups[i]->showInfo();
			cout << endl;
		}
	}
};

int main()
{
	//setlocale(LC_ALL, "RU");
	srand(time(NULL));
	system("color b");
	
	School sch1;
	Student st1;
	Group gr1;
	Group gr2;

	sch1.addStudent(st1);
	sch1.addGroup(gr1);
	sch1.distAllStudIntoGroups();
	sch1.addGroup(gr2);
	sch1.moveStudentByIdToGroupByIndex(1, 1);
	sch1.showInfo();
}
