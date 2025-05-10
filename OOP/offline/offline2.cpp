#include <bits/stdc++.h>
using namespace std;

class Course
{
private:
    string name;
    float creditHour;

public:
    Course()
    {
        name = "";
        creditHour = 0.0;
    }
    Course(string name, float creditHour)
    {
        this->name = name;
        this->creditHour = creditHour;
    }
    string getName()
    {
        return name;
    }
    float getCreditHour()
    {
        return creditHour;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setCreditHour(float creditHour)
    {
        this->creditHour = creditHour;
    }
    void display()
    {
        cout << "Course Name : " << name << " CreditHour : " << creditHour;
    }
};
class Student
{
private:
    string name;
    int id;
    Course *courses;
    int totalCourses;
    int maxCourses;
    float *gradePoints;

public:
    Student()
    {
        name = "";
        id = -1;
        maxCourses = 10;
        courses = new Course[maxCourses];
        totalCourses = 0;
        gradePoints = new float[maxCourses];
    }
    Student(string name, int id, int maxCourses)
    {
        this->name = name;
        this->id = id;
        this->maxCourses = maxCourses;
        this->courses = new Course[maxCourses];
        totalCourses = 0;
        this->gradePoints = new float[maxCourses];
    }
    Student(const Student &s)
    {
        this->name = s.name;
        this->id = s.id;
        this->maxCourses = s.maxCourses;
        this->totalCourses = s.totalCourses;
        this->courses = new Course[maxCourses];
        this->gradePoints = new float[maxCourses];
        for (int i = 0; i < s.totalCourses; i++)
        {
            this->courses[i] = s.courses[i];
            this->gradePoints[i] = s.gradePoints[i];
        }
    }
    ~Student()
    {
        delete[] courses;
        delete[] gradePoints;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setInfo(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    void addCourse(Course c)
    {
        if (totalCourses >= maxCourses)
        {
            cout << "course cant be added";
        }
        else
        {
            courses[totalCourses] = c;
            totalCourses++;
        }
    }
    void addCourse(Course c, float gradePoints)
    {
        if (totalCourses >= maxCourses)
        {
            cout << "course cant be added";
        }
        else
        {
            courses[totalCourses] = c;
            this->gradePoints[totalCourses] = gradePoints;
            totalCourses++;
        }
    }
    void setGradePoint(Course c, float gradePoint)
    {
        int idx = -1;
        for (int i = 0; i < totalCourses; i++)
        {
            if ((courses[i].getName() == c.getName()) &&
                (courses[i].getCreditHour() == c.getCreditHour()))
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            cout << "Not found";
        }
        else
        {
            gradePoints[idx] = gradePoint;
        }
    }
    void setGradePoint(float *gradePoints, int n)
    {
        if (n > totalCourses)
        {
            n = totalCourses;
        }
        for (int i = 0; i < n; i++)
        {
            this->gradePoints[i] = gradePoints[i];
        }
    }
    float getCGPA()
    {
        float totalGpa = 0.0, totalHour = 0.0;
        for (int i = 0; i < totalCourses; i++)
        {

            totalGpa = totalGpa + gradePoints[i] * courses[i].getCreditHour();
            totalHour = totalHour + courses[i].getCreditHour();
        }
        if (totalHour == 0.0f)
        {
            return 0.0;
        }
        else
        {
            return totalGpa / totalHour;
        }
    }
    float getGradePoint(Course c)
    {
        int idx = -1;
        for (int i = 0; i < totalCourses; i++)
        {
            if ((courses[i].getName() == c.getName()) &&
                (courses[i].getCreditHour() == c.getCreditHour()))
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {

            return 0.0f;
        }
        else
        {
            return gradePoints[idx];
        }
    }
    int getTotalCourses()
    {
        return totalCourses;
    }
    float getTotalCreditHours()
    {
        float totalHour = 0.0;
        for (int i = 0; i < totalCourses; i++)
        {
            if (gradePoints[i] >= 2)
            {

                totalHour = totalHour + courses[i].getCreditHour();
            }
        }
        return totalHour;
    }
    string getName()
    {
        return name;
    }
    Course getMostFavoriteCourse()
    {
        if (totalCourses <= 0)
        {
            return Course();
        }
        else
        {
            Course mx = courses[0];
            float m = gradePoints[0];
            for (int i = 1; i < totalCourses; ++i)
            {
                if ((gradePoints[i] > m) && gradePoints[i] >= 2)
                {
                    mx = courses[i];
                    m = gradePoints[i];
                }
            }
            return mx;
        }
    }
    Course getLeastFavoriteCourse()
    {
        if (totalCourses <= 0)
        {
            return Course();
        }
        else
        {
            Course mx = courses[0];
            float m = gradePoints[0];
            for (int i = 1; i < totalCourses; ++i)
            {
                if ((gradePoints[i] < m) && gradePoints[i] >= 2)
                {
                    mx = courses[i];
                    m = gradePoints[i];
                }
            }
            return mx;
        }
    }
    Course *getFailedCourses(int &count)
    {
        count = 0;
        for (int i = 0; i < totalCourses; ++i)
        {
            if (gradePoints[i] < 2.0)
            {
                count++;
            }
        }
        Course *failed = new Course[count];
        int j = 0;
        for (int i = 0; i < totalCourses; ++i)
        {
            if (gradePoints[i] < 2.0)
            {
                failed[j++] = courses[i];
            }
        }
        return failed;
    }
    void display()
    {
        cout << "==================================" << endl;
        cout << "Student Name: " << name << ", ID: " << id << endl;
        for (int i = 0; i < totalCourses; ++i)
        {
            courses[i].display();
            cout << ", gradePoint: " << gradePoints[i] << endl;
        }
        cout << "CGPA: " << getCGPA() << endl;
        cout << "Total Credit Hours Earned: " << getTotalCreditHours() << endl;
        cout << "Most Favorite Course: " << getMostFavoriteCourse().getName() << endl;
        cout << "Least Favorite Course: " << getLeastFavoriteCourse().getName() << endl;
    }
};
Student **students = new Student *[100];
static int totalStudents = 0;

Student getTopper()
{
    float maxCGPA = -1;
    int topperIndex = -1;
    for (int i = 0; i < totalStudents; ++i)
    {
        float cgpa = students[i]->getCGPA();
        if (cgpa > maxCGPA)
        {
            maxCGPA = cgpa;
            topperIndex = i;
        }
    }
    if (topperIndex != -1)
    {
        return *students[topperIndex]; // Return a copy (safe)
    }
    else
    {
        return Student(); // Return default if no student found
    }
}

Student getTopper(Course c)
{
    float maxGrade = -1;
    int topperIndex = -1;
    for (int i = 0; i < totalStudents; ++i)
    {
        float gp = students[i]->getGradePoint(c);
        if (gp >= 2.0 && gp > maxGrade)
        {
            maxGrade = gp;
            topperIndex = i;
        }
    }
    if (topperIndex != -1)
    {
        return *students[topperIndex]; // Return a copy (safe)
    }
    else
    {
        return Student(); // Return default if no topper found
    }
}

int main()
{
    // generate courses
    const int COURSE_COUNT = 6;
    Course courses[COURSE_COUNT] = {
        Course("CSE107", 3),
        Course("CSE105", 3),
        Course("CSE108", 1.5),
        Course("CSE106", 1.5),
        Course("EEE164", 0.75),
        Course("ME174", 0.75),
    };
    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25};
    // generate students
    Student s1 = Student("Sheldon", 1, 5);
    students[totalStudents++] = &s1;
    // add courses to s1
    s1.addCourse(courses[0]);
    s1.addCourse(courses[1]);
    s1.addCourse(courses[2]);
    s1.addCourse(courses[3]);
    s1.addCourse(courses[4]);
    s1.addCourse(courses[5]);
    s1.setGradePoint(gradePoints, s1.getTotalCourses());
    s1.display();
    Student s2 = Student("Penny", 2, 5);
    students[totalStudents++] = &s2;
    s2.addCourse(courses[0]);
    s2.addCourse(courses[2]);
    s2.addCourse(courses[5]);
    s2.setGradePoint(gradePoints, s2.getTotalCourses());
    s2.setGradePoint(courses[0], 3.25);
    s2.display();
    Student s3 = s2;
    students[totalStudents++] = &s3;
    s3.setName("Leonard");
    s3.setId(3);
    s3.setGradePoint(gradePoints, s3.getTotalCourses());
    s3.addCourse(courses[1], 3.75);
    s3.display();
    Student s4 = s3;
    students[totalStudents++] = &s4;
    s4.setInfo("Howard", 4);
    s4.setGradePoint(gradePoints, s4.getTotalCourses());
    s4.addCourse(courses[3], 3.75);
    s4.display();
    Student s5 = s4;
    students[totalStudents++] = &s5;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(gradePoints, s5.getTotalCourses());
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();
    int failedCount;
    Course *failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i)
    {
        failedCourses[i].display();
        cout << endl;
    }
    delete[] failedCourses;
    cout << "==================================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < COURSE_COUNT; ++i)
    {
        Course c = courses[i];
        Student topperInCourse = getTopper(c);
        cout << "Topper in " << c.getName() << ": " << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " << topperInCourse.getGradePoint(c) << endl;
        cout << "==================================" << endl;
    }
    return 0;
}
