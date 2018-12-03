/*
  Louis Gomez
  B343X495
  Program
  */

  class Errors: public exception
  {

  private:
    string message;

  public:
    Errors(string str)
    {
      message = str;
    }
    string what()
    {
      return message;
    }
  };
