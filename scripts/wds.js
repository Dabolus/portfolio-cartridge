module.exports = {
  extensions: ['.ts', '.js'],
  esbuild: {
    platform: 'node',
    target: ['node16'],
    format: 'cjs',
    minify: true,
    bundle: true,
    sourcemap: true,
  },
};
