/*
int main(void) {
	printf("this is test\n");
	/*mytcpserver mytest("0.0.0.0", 12732);
	mytest.bind_socket();
	mytest.listen_socket(1024);
	system("netstat -nlt|grep 12732");
	//sleep(10);
	string regtext = "[a-z]*", matchtext = "da4awdafcad";
	boost::regex reg(regtext);
	bool b = boost::regex_match(matchtext, reg);
	cout << "if match: " << b << endl;
	*/

	/*using namespace boost;
	regex reg1("or");
	smatch m;
	string s = "fafawr delete or new";
	if (regex_search(s, m, reg1)) {
		//match?
		string m0out = m[0], m1out = m[1], m2out = m[2];
		cout << "this is m0 " << m0out << endl;
		cout << "this is m1 " << m1out << endl;
		cout << "this is m2 " << m2out << endl;
		cout << m.size() << endl;
		if (m[1].matched) {
			cout << m[1] << endl;
			cout<<"(new) matched\n"<<endl;
		}
		if (m[2].matched) {
			cout << m[2] << endl;
			cout << "(delete) matched\n" << endl;
		}
	}*/
	/*
	using namespace boost;
	regex reg("(new)|(delete)");
	smatch m;
	string s = "Calls to new must be followed by delete. \
 Calling simply new results in a leak!";
	int new_counter = 0, del_counter = 0;
	string::const_iterator begin = s.begin(), end = s.end();
	while (regex_search(begin, end, m, reg)) {
		m[1].matched ? ++new_counter : ++del_counter;
		begin = m[0].second;
	}
	cout << "new match: " << new_counter << " times" << endl;
	cout << "del match: " << del_counter << " times" << endl;
	*/
	/*
	regex reg("(Colo)(u)(r)([s,]{1,3})", regex::icase | regex::perl);
	string s = "Colour, colours, color, colourize";
	s = regex_replace(s, reg, "$1$3$4");
	cout << s << endl;
	*/
	/*
	asio::io_context io;
	asio::steady_timer timer(io, asio::chrono::seconds(5));
	timer.wait();
	cout << "hello" << endl;
	*/
	/*
	asio::io_context io;
	asio::steady_timer mytimer(io, asio::chrono::seconds(25));
	mytimer.async_wait(&print);
	//sleep(10);
	io.run();
	cout << "after run" << endl;
	*/
	/*
		asio::io_context io;
		int count = 0;
		asio::steady_timer t(io, asio::chrono::seconds(1));
		t.async_wait(bind(print, asio::placeholders::error, &t, &count));
		io.run();
		cout << "Final count is " << count << endl;

		return 0;
	}
	*/
	/*
	void print(const boost::system::error_code& )
	{
		std::cout << "Hello, world!" << std::endl;
	}

	int main()
	{
		boost::asio::io_context io;

		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
		t.async_wait(&print);
		io.run();

		return 0;
	}*/
	/*
	void print(const boost::system::error_code& ,
		boost::asio::steady_timer* t, int* count)
	{
		if (*count < 5)
		{
			std::cout << *count << std::endl;
			++(*count);
			t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
			t->async_wait(boost::bind(print,
				boost::asio::placeholders::error, t, count));
		}
	}

	int main()
	{
		boost::asio::io_context io;
		int count = 0;
		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
		t.async_wait(boost::bind(print,
			boost::asio::placeholders::error, &t, &count));

		io.run();
		std::cout << "Final count is " << count << std::endl;

		return 0;
	}*/
