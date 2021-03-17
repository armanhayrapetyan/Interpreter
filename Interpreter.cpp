#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum types { INT = 1, STRING, CHAR, UNKOWN };

struct Estragon
{
	std::string name = "";
	types type;
	std::string value;
};

int n = 0;
std::vector <Estragon> obj;
std::string commands[] = { "Estragon","TalkLucky","Godot's_arrival","UntilNextDay" };//int,cout,if,while
int estr(const std::vector<std::string>& token, int size, int i);
int talk(const std::vector<std::string>& token, int size, int i);
int arrival(const std::vector<std::string>& token, int size, int i);
int until(const std::vector<std::string>& token, int size, int i);
int assign(const std::vector<std::string>& token, int size, int i);

int main() {
	std::vector <std::string> token;
	std::ifstream file("c:\\users\\araks\\desktop\\Input Code.txt");

	if (!file.is_open())
	{
		std::cout << "Can't open the file";
	}
	while (!file.eof()) {
		std::string line;
		getline(file, line);
		std::string str = "";
		int i = 0;
		while (i < line.size())
		{
			if (line[i] != ' ')
			{
				str += line[i];
				++i;
				if (i == line.size())
				{
					token.push_back(str);
				}
			}
			else
			{
				token.push_back(str);
				str = line[i];
				token.push_back(str);
				++i;
				str = "";
			}
		}
		if (token[0] == commands[0])
		{
			estr(token, token.size(), 1);
		}
		else if (token[0] == commands[1])
		{
			talk(token, token.size(), 1);
		}
		else if (token[0] == commands[2])
		{
			arrival(token,token.size(),1);
		}
		else if (token[0] == commands[3])
		{
			until(token,token.size(),1);
		}
		else
		{
			assign(token,token.size(),0);
		}
		while (!token.empty())
		{
			token.pop_back();
		}
	}
	return 0;
}

int estr(const std::vector<std::string>& token, int size, int i)
{
	do
	{
		if (token[i] == " ")
		{
			++i;
		}
	} while (token[i] == " ");
	if (i < size)
	{
		if (token[i] != "=" && token[i] != ";")
		{
			bool is_true = true;
			int m = 0;
			if (obj.size() != 0)
			{
				for (int q = 0; q < obj.size(); ++q)
				{

					if (token[i] == obj[q].name)
					{
						std::cout << "error";
						return i;
					}
					else
					{
						m = n;
					}

				}
				if (m != 0)
				{
					obj.push_back(Estragon());
					obj[m].name += token[i];
				}
			}
			else
			{
				obj.push_back(Estragon());
				obj[n].name += token[i];
			}
			++i;
			if (i < size)
			{
				do
				{
					if (token[i] == " ")
					{
						++i;
					}
				} while (token[i] == " ");
				if (i < size)
				{
					if (token[i] != "=")
					{
						if (token[i] == ";")
						{
							obj[n].type = UNKOWN;
							obj[n].value = "";
							++i;
							if (i < size)
							{
								do
								{
									if (token[i] == " ")
									{
										++i;
									}
								} while (token[i] == " ");
								if (i != size)
								{
									std::cout << "error";
									return 0;
								}
							}
							++n;
							return i;
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					else
					{
						++i;
						if (i < size)
						{
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "\"" && token[i] != "\'")
								{
									bool is_ture = true;
									bool is_false = false;
									for (int k = 0; k < token[i].size(); ++k)
									{
										if (!(token[i][k] >= 48 && token[i][k] <= 57))
										{
											is_true = false;
											is_false = true;
										}
									}
									if (is_true)
									{
										obj[n].type = INT;
										obj[n].value = token[i];
										++i;
										if (i < size)
										{
											do
											{
												if (token[i] == " ")
												{
													++i;
												}
											} while (token[i] == " ");
											if (i < size)
											{
												if (token[i] != ";")
												{
													std::cout << "error";
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else if (is_false)
									{
										for (int q = 0; q < obj.size(); ++q)
										{
											if (token[i] == obj[q].name)
											{
												obj[n].value = obj[q].value;
												obj[n].type = obj[q].type;
												break;
											}
										}
										++i;
										if (i < size)
										{
											do
											{
												if (token[i] == " ")
												{
													++i;
												}
											} while (token[i] == " ");
											if (i < size)
											{
												if (token[i] != ";")
												{
													std::cout << "error";
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
								}
								else if (token[i] == "\'")
								{
									++i;
									if (i < size)
									{
										do
										{
											if (token[i] == " ")
											{
												++i;
											}
										} while (token[i] == " ");
										if (token[i].size() == 1)
										{
											if (token[i][0] >= 32 && token[i][0] <= 255)
											{
												obj[n].type = CHAR;
												obj[n].value = token[i];
												++i;
												if (i < size)
												{
													if (token[i] != "\'")
													{
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] != "\'")
															{
																std::cout << "error";
																return 0;
															}
														}
														else
														{
															++i;
															if (i < size)
															{
																if (token[i] != ";")
																{
																	do
																	{
																		if (token[i] == " ")
																		{
																			++i;
																		}
																	} while (token[i] == " ");
																	if (token[i] != ";")
																	{
																		std::cout << "error";
																		return 0;
																	}
																}
															}
															else
															{
																std::cout << "error";
																return 0;
															}
														}
													}
													else
													{
														std::cout << "error";
														return 0;
													}
												}
												else
												{
													std::cout << "error";
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
								else if (token[i] == "\"")
								{
									++i;
									if (i < size)
									{
										do
										{
											if (token[i] == " ")
											{
												++i;
											}
										} while (token[i] == " ");
										obj[n].type = STRING;
										obj[n].value = token[i];
										++i;
										if (i < size)
										{
											if (token[i] != "\"")
											{
												do
												{
													if (token[i] == " ")
													{
														++i;
													}
												} while (token[i] == " ");
												if (i < size)
												{
													if (token[i] != "\"")
													{
														std::cout << "error";
														return 0;
													}
												}
												else
												{
													++i;
													if (i < size)
													{
														if (token[i] != ";")
														{
															do
															{
																if (token[i] == " ")
																{
																	++i;
																}
															} while (token[i] == " ");
															if (token[i] != ";")
															{
																std::cout << "error";
																return 0;
															}
														}
													}
													else
													{
														std::cout << "error";
														return 0;
													}
												}
											}
											else
											{
												++i;
												if (i < size)
												{
													if (token[i] != ";")
													{
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (token[i] != ";")
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													std::cout << "error";
													return 0;
												}
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
				}
				else
				{
					std::cout << "error";
					return 0;
				}
			}
			else
			{
				std::cout << "error";
				return 0;
			}
		}
		else
		{
			std::cout << "error";
			return 0;
		}
	}
	else
	{
		std::cout << "error";
		return 0;
	}
	++n;

	return i;
}

int talk(const std::vector<std::string>& token, int size, int i)
{

	do
	{
		if (token[i] == " ")
		{
			++i;
		}
	} while (token[i] == " ");

	if (i < size)
	{
		if (token[i] != "~")
		{
			std::cout << "error";
			return 0;
		}
		else
		{
			++i;
			do
			{
				if (token[i] == " ")
				{
					++i;
				}
			} while (token[i] == " ");

			if (i < size)
			{
				bool is_true = true;
				bool is_false = false;
				for (int k = 0; k < token[i].size(); ++k)
				{
					if (!(token[i][k] >= 48 && token[i][k] <= 57))
					{
						is_true = false;
					}
					if (!(token[i][k] >= 48 && token[i][k] <= 57))
					{
						is_false = true;
					}
				}
				if (is_true)
				{

					int temp;
					int num = 0;
					for (int j = 0; j < token[i].size(); ++j)
					{
						temp = token[i][j] - '0';
						num = num * 10 + temp;
					}
					++i;
					if (i < size)
					{
						if (token[i] != ";")
						{
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (token[i] != ";") {
								std::cout << "error";
								return 0;
							}
							else
							{
								std::cout << num;
							}
						}
					}
					else
					{
						std::cout << "error";
						return 0;
					}
				}
				else if (is_false)
				{
					for (int q = 0; q < obj.size(); ++q)
					{
						if (token[i] == obj[q].name)
						{
							if (obj[q].type == INT)
							{
								int temp;
								int num = 0;
								for (int j = 0; j < obj[q].value.size(); ++j)
								{
									temp = obj[q].value[j] - '0';
									num = num * 10 + temp;
								}
								++i;
								if (i < size)
								{
									if (token[i] != ";")
									{
										do
										{
											if (token[i] == " ")
											{
												++i;
											}
										} while (token[i] == " ");
										if (token[i] != ";") {
											std::cout << "error";
											return 0;
										}
										else
										{
											std::cout << num;
										}
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else if (obj[q].type == STRING)
							{
								++i;
								if (i < size)
								{
									if (token[i] != ";")
									{
										do
										{
											if (token[i] == " ")
											{
												++i;
											}
										} while (token[i] == " ");
										if (token[i] != ";") {
											std::cout << "error";
											return 0;
										}
										else
										{
											std::cout << obj[q].value;
										}
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else if (obj[q].type == CHAR)
							{
								++i;
								if (i < size)
								{
									if (token[i] != ";")
									{
										do
										{
											if (token[i] == " ")
											{
												++i;
											}
										} while (token[i] == " ");
										if (token[i] != ";") {
											std::cout << "error";
											return 0;
										}
										else
										{
											std::cout << obj[q].value;
										}
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else if (obj[q].type == UNKOWN)
							{
								std::cout << "error";
								return 0;
							}
						}
					}
				}
			}
			else
			{
				std::cout << "error";
				return 0;
			}
		}

	}
	else
	{
		std::cout << "error";
		return 0;
	}
	return i;
}

int arrival(const std::vector<std::string>& token, int size, int i)
{
	int e = 0;
	int r = 0;
	do
	{
		if (token[i] == " ")
		{
			++i;
		}
	} while (token[i] == " ");
	if (i < size)
	{
		if (token[i] != "|")
		{
			std::cout << "error";
			return 0;
		}
		else
		{
			++i;
			do
			{
				if (token[i] == " ")
				{
					++i;
				}
			} while (token[i] == " ");
			if (i < size)
			{
				bool is_true = true;
				for (int q = 0; q < obj.size(); ++q)
				{
					if (token[i] == obj[q].name)
					{
						e = q;
						++i; 
						is_true = false;
						break;
					}
				}
				if (is_true)
				{
					std::cout << "there is no variable with that name";
					return i;
				}
				do
				{
					if (token[i] == " ")
					{
						++i;
					}
				} while (token[i] == " ");
				if (i < size)
				{
					if (token[i] == "<")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{ 
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 < num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value < obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{	
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value < obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{	
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if(token[i]==commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					else if (token[i] == ">")
{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 > num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value > obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value > obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					else if (token[i] == "==")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 == num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value == obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value == obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					else if (token[i] == "!=")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 != num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value != obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value != obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}

					if (token[i] == ">=")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 >= num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value >= obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error"; 
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value >= obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error"; 
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}

					else if (token[i] == "<=")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 <= num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error"; 
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == STRING)
											{
												if (obj[e].value <= obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else if (obj[e].type == CHAR)
											{
												if (obj[e].value <= obj[r].value)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[1])
															{
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															else if (token[i] == commands[2])
															{
																i = arrival(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																if (i < size)
																{
																	if (token[i] != ")")
																	{
																		std::cout << "error";
																		return 0;
																	}
																	else
																	{
																		++i;
																		do
																		{
																			if (token[i] == " ")
																			{
																				++i;
																			}
																		} while (token[i] == " ");
																		if (i < size)
																		{
																			if (token[i] != ";")
																			{
																				do
																				{
																					if (token[i] == " ")
																					{
																						++i;
																					}
																				} while (token[i] == " ");
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																			}
																		}
																		else
																		{
																			std::cout << "error";
																			return 0;
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return i;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
				}
				else
				{
					std::cout << "error";
					return 0;
				}
			}
			else
			{
				std::cout << "error";
				return 0;
			}
		}
	}
	else
	{
		std::cout << "error";
		return 0;
	}
	return i;
}

int until(const std::vector<std::string>& token, int size, int i)
{
	int e = 0;
	int r = 0;
	do
	{
		if (token[i] == " ")
		{
			++i;
		}
	} while (token[i] == " ");
	if (i < size)
	{
		if (token[i] != "|")
		{
			std::cout << "error";
			return 0;
		}
		else
		{
			++i;
			do
			{
				if (token[i] == " ")
				{
					++i;
				}
			} while (token[i] == " ");
			if (i < size)
			{
				bool is_true = true;
				for (int q = 0; q < obj.size(); ++q)
				{
					if (token[i] == obj[q].name)
					{
						e = q;
						++i;
						is_true = false;
						break;
					}
				}
				if (is_true)
				{
					std::cout << "there is no variable with that name";
					return i;
				}
				do
				{
					if (token[i] == " ")
					{
						++i;
					}
				} while (token[i] == " ");
				if (i < size)
				{
					if (token[i] == "<")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 < num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																std::string var_name;
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															if (token[i] == commands[1])
															{
																std::string var_name;
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
												return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					
					if (token[i] == ">")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 > num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																std::string var_name;
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															if (token[i] == commands[1])
															{
																std::string var_name;
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}

					if (token[i] == "<=")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 <= num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																std::string var_name;
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															if (token[i] == commands[1])
															{
																std::string var_name;
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					if (token[i] == ">=")
					{
						++i;
						do
						{
							if (token[i] == " ")
							{
								++i;
							}
						} while (token[i] == " ");
						if (i < size)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									r = q;
									++i;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "there is no variable with such name";
								return i;
							}
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (i < size)
							{
								if (token[i] != "|")
								{
									std::cout << "error";
									return 0;
								}
								else
								{
									++i;
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (obj[e].type == obj[r].type)
										{
											if (obj[e].type == INT)
											{
												int temp1;
												int num1 = 0;
												for (int j = 0; j < obj[e].value.size(); ++j)
												{
													temp1 = obj[e].value[j] - '0';
													num1 = num1 * 10 + temp1;
												}
												int temp2;
												int num2 = 0;
												for (int j = 0; j < obj[r].value.size(); ++j)
												{
													temp2 = obj[r].value[j] - '0';
													num2 = num2 * 10 + temp2;
												}
												if (num1 >= num2)
												{
													if (token[i] != "(")
													{
														std::cout << "error";
														return 0;
													}
													else
													{
														++i;
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (i < size)
														{
															if (token[i] == commands[0])
															{
																std::string var_name;
																i = estr(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
															if (token[i] == commands[1])
															{
																std::string var_name;
																i = talk(token, token.size(), ++i);
																++i;
																do
																{
																	if (token[i] == " ")
																	{
																		++i;
																	}
																} while (token[i] == " ");
																int j = 0;
																if (token[i][j] == '+')
																{
																	++j;
																	if (token[i][j] == '+')
																	{
																		++j;
																		while (j != token[i].size())
																		{
																			var_name += token[i][j++];
																		}
																		if (var_name == obj[e].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[e].value.size(); ++j)
																			{
																				temp3 = obj[e].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[e].value = s;
																			until(token, token.size(), 1);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ";")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ")")
																						{
																							std::cout << "error";
																							return 0;
																						}
																						else
																						{
																							++i;
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								do
																								{
																									if (token[i] == " ")
																									{
																										++i;
																									}
																								} while (token[i] == " ");
																								if (token[i] != ";") {
																									std::cout << "error";
																									return 0;
																								}
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																		else if (var_name == obj[r].name)
																		{
																			int temp3;
																			int num3 = 0;
																			for (int j = 0; j < obj[r].value.size(); ++j)
																			{
																				temp3 = obj[r].value[j] - '0';
																				num3 = num3 * 10 + temp3;
																			}
																			++num3;
																			std::string s = std::to_string(num3);
																			obj[r].value = s;
																			until(token, token.size(), i);
																			++i;
																			do
																			{
																				if (token[i] == " ")
																				{
																					++i;
																				}
																			} while (token[i] == " ");
																			if (i < size)
																			{
																				if (token[i] != ")")
																				{
																					std::cout << "error";
																					return 0;
																				}
																				else
																				{
																					++i;
																					do
																					{
																						if (token[i] == " ")
																						{
																							++i;
																						}
																					} while (token[i] == " ");
																					if (i < size)
																					{
																						if (token[i] != ";")
																						{
																							do
																							{
																								if (token[i] == " ")
																								{
																									++i;
																								}
																							} while (token[i] == " ");
																							if (token[i] != ";")
																							{
																								std::cout << "error";
																								return 0;
																							}
																						}
																					}
																					else
																					{
																						std::cout << "error";
																						return 0;
																					}
																				}
																			}
																			else
																			{
																				std::cout << "error";
																				return 0;
																			}
																		}
																	}
																}
																else
																{
																	std::cout << "error";
																	return 0;
																}
															}
														}
														else
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													return 0;
												}
											}
											else
											{
												std::cout << "error";
												return 0;
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
				}
				else
				{
					std::cout << "error";
					return 0;
				}
			}
			else
			{
				std::cout << "error";
				return 0;
			}
		}
	}
	else
	{
		std::cout << "error";
		return 0;
	}
}

int assign(const std::vector<std::string>& token, int size, int i)
{
	int v = 0;
	bool is__true=true;
	for (int ix = 0; ix < obj.size(); ++ix)
	{
		if (token[i] == obj[ix].name)
		{
			is__true = false;
			++i;
			v = ix;
			break;
		}
	}
	if (is__true)
	{
		std::cout << "Undeclared variable.";
		return 0;
	}
	do
	{
		if (token[i] == " ")
		{
			++i;
		}
	} while (token[i] == " ");
	if (i < size)
	{
		if (token[i] != "=")
		{
			std::cout << "error";
			return 0;
		}
		else
		{
			++i;
			if (i < size)
			{
				do
				{
					if (token[i] == " ")
					{
						++i;
					}
				} while (token[i] == " ");
				if (i < size)
				{
					if (token[i] != "\"" && token[i] != "\'")
					{
						bool is_true = true;
						bool is_false = false;
						for (int k = 0; k < token[i].size(); ++k)
						{
							if (!(token[i][k] >= 48 && token[i][k] <= 57))
							{
								is_true = false;
								is_false = true;
							}
						}
						if (is_true)
						{
							obj[v].type = INT;
							obj[v].value = token[i];
							++i;
							if (i < size)
							{
								do
								{
									if (token[i] == " ")
									{
										++i;
									}
								} while (token[i] == " ");
								if (i < size)
								{
									if (token[i] != ";")
									{
										std::cout << "error";
										return 0;
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else if (is_false)
						{
							bool is_true = true;
							for (int q = 0; q < obj.size(); ++q)
							{
								if (token[i] == obj[q].name)
								{
									obj[v].value = obj[q].value;
									obj[v].type = obj[q].type;
									is_true = false;
									break;
								}
							}
							if (is_true)
							{
								std::cout << "There is no declared variable with that name.";
							}
							++i;
							if (i < size)
							{
								do
								{
									if (token[i] == " ")
									{
										++i;
									}
								} while (token[i] == " ");
								if (i < size)
								{
									if (token[i] != ";")
									{
										std::cout << "error";
										return 0;
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
					}
					else if (token[i] == "\'")
					{
						++i;
						if (i < size)
						{
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							if (token[i].size() == 1)
							{
								if (token[i][0] >= 32 && token[i][0] <= 255)
								{
									obj[v].type = CHAR;
									obj[v].value = token[i];
									++i;
									if (i < size)
									{
										if (token[i] != "\'")
										{
											do
											{
												if (token[i] == " ")
												{
													++i;
												}
											} while (token[i] == " ");
											if (i < size)
											{
												if (token[i] != "\'")
												{
													std::cout << "error";
													return 0;
												}
											}
											else
											{
												++i;
												if (i < size)
												{
													if (token[i] != ";")
													{
														do
														{
															if (token[i] == " ")
															{
																++i;
															}
														} while (token[i] == " ");
														if (token[i] != ";")
														{
															std::cout << "error";
															return 0;
														}
													}
												}
												else
												{
													std::cout << "error";
													return 0;
												}
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
								else
								{
									std::cout << "error";
									return 0;
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
					else if (token[i] == "\"")
					{
						++i;
						if (i < size)
						{
							do
							{
								if (token[i] == " ")
								{
									++i;
								}
							} while (token[i] == " ");
							obj[v].type = STRING;
							obj[v].value = token[i];
							++i;
							if (i < size)
							{
								if (token[i] != "\"")
								{
									do
									{
										if (token[i] == " ")
										{
											++i;
										}
									} while (token[i] == " ");
									if (i < size)
									{
										if (token[i] != "\"")
										{
											std::cout << "error";
											return 0;
										}
									}
									else
									{
										++i;
										if (i < size)
										{
											if (token[i] != ";")
											{
												do
												{
													if (token[i] == " ")
													{
														++i;
													}
												} while (token[i] == " ");
												if (token[i] != ";")
												{
													std::cout << "error";
													return 0;
												}
											}
										}
										else
										{
											std::cout << "error";
											return 0;
										}
									}
								}
								else
								{
									++i;
									if (i < size)
									{
										if (token[i] != ";")
										{
											do
											{
												if (token[i] == " ")
												{
													++i;
												}
											} while (token[i] == " ");
											if (token[i] != ";")
											{
												std::cout << "error";
												return 0;
											}
										}
									}
									else
									{
										std::cout << "error";
										return 0;
									}
								}
							}
							else
							{
								std::cout << "error";
								return 0;
							}
						}
						else
						{
							std::cout << "error";
							return 0;
						}
					}
				}
				else
				{
					std::cout << "error";
					return 0;
				}
			}
			else
			{
				std::cout << "error";
				return 0;
			}
		}
	}
	else
	{
		std::cout << "error";
		return 0;
	}
}