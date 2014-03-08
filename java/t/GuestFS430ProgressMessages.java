/* libguestfs Java bindings
 * Copyright (C) 2014 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

import java.io.*;
import java.util.HashMap;
import com.redhat.et.libguestfs.*;

public class GuestFS430ProgressMessages
{
    static class CallbackEvent implements EventCallback
    {
        private int callback_invoked = 0;

        public void event (long event, int eh, String buffer, long[] array)
        {
            callback_invoked++;
        }

        public int getCallbackInvoked ()
        {
            return callback_invoked;
        }

        public void resetCallbackInvoked ()
        {
            callback_invoked = 0;
        }
    }

    public static void main (String[] argv)
    {
        try {
            GuestFS g = new GuestFS ();
            g.add_drive ("/dev/null");
            g.launch ();

            // Grab all messages into an event handler that just
            // prints each event.
            CallbackEvent e = new CallbackEvent ();
            int eh = g.set_event_callback (e, GuestFS.EVENT_PROGRESS);

            String[] args = { "5" };
            String r = g.debug ("progress", args);
            assert r.equals ("ok");
            assert e.getCallbackInvoked () > 0;

            e.resetCallbackInvoked ();
            g.delete_event_callback (eh);
            r = g.debug ("progress", args);
            assert r.equals ("ok");
            assert e.getCallbackInvoked () == 0;

            g.set_event_callback (e, GuestFS.EVENT_PROGRESS);
            r = g.debug ("progress", args);
            assert r.equals ("ok");
            assert e.getCallbackInvoked () > 0;

            g.close ();
        }
        catch (Exception exn) {
            System.err.println (exn);
            System.exit (1);
        }
    }
}
