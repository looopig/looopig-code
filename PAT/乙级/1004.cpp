#include <iostream>

class Student {
private:
  char name[15] = "", student_number[15] = "";
  int grad = 0;

public:
  Student(int grad);
  void get_name_num_grad();
  void print_name_num() const;
  Student compare_max(Student &max_student);
  Student compare_min(Student &min_student);
};
Student::Student(int grad) : grad(grad) {}

void Student::get_name_num_grad() {
  std::cin >> name >> student_number >> grad;
}

void Student::print_name_num() const {
  std::cout << name << " " << student_number << std::endl;
}

Student Student::compare_max(Student &max_student) {
  if (grad >= max_student.grad)
    max_student = *this;

  return max_student;
}

Student Student::compare_min(Student &min_student) {
  if (grad <= min_student.grad)
    min_student = *this;

  return min_student;
}

int main() {
  int student_num;
  Student max_student(0), min_student(100), student(0);
  std::cin >> student_num;
  while (student_num--) {
    student.get_name_num_grad();
    student.compare_max(max_student);
    student.compare_min(min_student);
  }
  max_student.print_name_num();
  min_student.print_name_num();
}
