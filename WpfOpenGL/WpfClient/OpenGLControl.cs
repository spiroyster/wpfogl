using System;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace WpfClient
{
    public class OpenGL
    {
        [DllImport("cppOgl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void OpenGLDraw(IntPtr hDc, float rotation);
        [DllImport("cppOgl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void OpenGLResize(int width, int height);
        [DllImport("cppOgl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int OpenGLInit(IntPtr hDc);
        [DllImport("cppOgl.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void OpenGLKill();
    }

    public partial class OpenGLControl : UserControl
    {
        public OpenGLControl()
        {
            InitializeComponent();
        }

        private float rotation_;
        private Timer timer_;

        private void FPS(Object myObject, EventArgs myEventArgs)
        {
            ++rotation_;
            Refresh();
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            Graphics graphics = Graphics.FromHwnd(this.Handle);
            int result = OpenGL.OpenGLInit(graphics.GetHdc());
            graphics.Dispose();

            rotation_ = 0;

            timer_ = new Timer();
            timer_.Tick += FPS;
            timer_.Interval = 1000 / 120;
            timer_.Start();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            OpenGL.OpenGLDraw(e.Graphics.GetHdc(), rotation_);
        }

        protected override void OnPaintBackground(PaintEventArgs e)
        {      
        }

        protected override void OnResize(EventArgs e)
        {
            base.OnResize(e);
            OpenGL.OpenGLResize(this.Width, this.Height);
        }
    }
}
