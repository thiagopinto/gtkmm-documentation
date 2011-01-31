/* gtkmm example Copyright (C) 2010 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <gtkmm.h>
#include <iostream>

#include "exampleapplication.h"

void on_open(const Gio::Application::type_vec_files& /* files */, 
  const Glib::ustring& /* hint */)
{
  std::cout << "open signal received" << std::endl;
}

int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv); //TODO: Make this unnecessary: Put it in Gtk::Application.

  Glib::RefPtr<ExampleApplication> application = 
    ExampleApplication::create("org.gtkmm.examples.application",
      Gio::APPLICATION_HANDLES_OPEN);
  application->signal_open().connect( sigc::ptr_fun(on_open) );

  // Start the application, showing the initial window, 
  // and opening extra windows for any files that it is asked to open,
  // for instance as a command-line parameter.
  // run() will return when the last window has been closed by the user.
  const int status = application->run(argc, argv);
  return status;
}